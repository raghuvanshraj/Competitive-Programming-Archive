/**
 *    author:	vulkan
 *    created:	18.09.2019 12:09:22 PM
**/
#include <bits/stdc++.h>

using namespace std;

struct task_t {
	int min_req;
	int inc;
};

bool comp_pos(task_t a, task_t b) {
	return a.min_req < b.min_req;
}

bool comp_neg(task_t a, task_t b) {
	return (a.min_req - a.inc) > (b.min_req - b.inc);
}

int maximal_subset(vector<task_t> pos_tasks, vector<task_t> neg_tasks, int r) {
	sort(pos_tasks.begin(), pos_tasks.end(), comp_pos);
	int i = 0;
	int count_pos = 0;
	int n_pos = pos_tasks.size();
	while (i < n_pos and pos_tasks[i].min_req <= r) {
		r += pos_tasks[i].inc;
		count_pos++;
		i++;
	}

	int n_neg = neg_tasks.size();
	int dp[n_neg + 1][r + 1];
	for (int i = 0; i < n_neg + 1; ++i) {
		for (int j = 0; j < r + 1; ++j) {
			dp[i][j] = 0;
		}
	}

	sort(neg_tasks.begin(), neg_tasks.end(), comp_neg);
	for (int i = 1; i < n_neg + 1; ++i) {
		for (int j = 0; j < r + 1; ++j) {
			if (j >= neg_tasks[i - 1].min_req and j - neg_tasks[i - 1].inc >= 0) {
				dp[i][j - neg_tasks[i - 1].inc] = max(dp[i][j - neg_tasks[i - 1].inc], dp[i - 1][j] + 1);
			}

			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	return *max_element(dp[n_neg], dp[n_neg] + r + 1) + count_pos;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, r;
	cin >> n >> r;
	vector<task_t> pos_tasks, neg_tasks;
	for (int i = 0; i < n; ++i) {
		int min_req, inc;
		cin >> min_req >> inc;
		if (inc >= 0) {
			pos_tasks.push_back({min_req, inc});
		} else {
			neg_tasks.push_back({min_req, -inc});
		}
	}

	int ans = maximal_subset(pos_tasks, neg_tasks, r);
	cout << ((ans == n) ? "YES" : "NO");

	return 0;
}