/**
 *    author:	vulkan
 *    created:	10.06.2020 12:25:30 PM
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int minRefuelStops(int target, int start, vector<vector<int>> &stations) {
	int n = stations.size();
	vector<LL> dp(n + 1, -1);
	dp[0] = start;
	priority_queue<pair<LL, LL>> max_heap;
	for (int i = 0; i <= n - 1; ++i) {
		max_heap.push({stations[i][1], stations[i][0]});
	}

	for (int i = 1; i <= n; ++i) {
		if (dp[i - 1] == -1) {
			break;
		}

		vector<pair<LL, LL>> temp;
		while (not max_heap.empty() and max_heap.top().second > dp[i - 1]) {
			temp.push_back(max_heap.top());
			max_heap.pop();
		}

		if (not max_heap.empty()) {
			dp[i] = dp[i - 1] + max_heap.top().first;
			max_heap.pop();
		}

		for (pair<LL, LL> x : temp) {
			max_heap.push(x);
		}
	}

	for (int i = 0; i <= n; ++i) {
		if (dp[i] >= target) {
			return i;
		}
	}

	return -1;
}

int main(int argc, char const *argv[]) {
	int start, target;
	cin >> start >> target;
	int n;
	cin >> n;
	vector<vector<int>> stations(n, vector<int>(2));
	for (int i = 0; i <= n - 1; ++i) {
		cin >> stations[i][0] >> stations[i][1];
	}

	cout << minRefuelStops(target, start, stations);

	return 0;
}