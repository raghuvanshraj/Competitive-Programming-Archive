/**
 *    author:	vulkan
 *    created:	12.04.2020 04:21:13 PM
**/
#include <bits/stdc++.h>

using namespace std;

struct job_t {
	int start, end, profit;
};

static bool comp(job_t &a, job_t &b) {
	return a.end < b.end;
}

static int binary_search(vector<job_t> &jobs, int i) {
	int s = 0, e = i - 1;
	int ans = -1;
	while (s < e) {
		int mid = (s + e) / 2;
		if (jobs[mid].end <= jobs[i].start) {
			ans = mid;
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}

	if (jobs[s].end <= jobs[i].start) {
		ans = s;
	}

	return ans;
}

int jobScheduling(vector<int> &start, vector<int> &end, vector<int> &profit) {
	int n = start.size();
	vector<job_t> jobs(n);
	for (int i = 0; i < n; ++i) {
		jobs[i].start = start[i];
		jobs[i].end = end[i];
		jobs[i].profit = profit[i];
	}

	sort(jobs.begin(), jobs.end(), comp);

	vector<int> dp(n);
	dp[0] = jobs[0].profit;
	for (int i = 1; i < n; ++i) {
		int j = binary_search(jobs, i);
		if (j != -1) {
			dp[i] = max(dp[j] + jobs[i].profit, dp[i - 1]);
		} else {
			dp[i] = max(jobs[i].profit, dp[i - 1]);
		}
	}

	return dp[n - 1];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> start(n), end(n), profit(n);
	for (int i = 0; i < n; ++i) {
		cin >> start[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> end[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> profit[i];
	}

	cout << jobScheduling(start, end, profit);

	return 0;
}