/**
 *    author:	vulkan
 *    created:	27.05.2020 08:19:25 PM
**/
#include <bits/stdc++.h>

using namespace std;

int findMaxForm(vector<string> &arr, int m, int n) {
	int sz = arr.size();
	vector<pair<int, int>> counts(sz);
	for (int i = 0; i <= sz - 1; ++i) {
		for (char c : arr[i]) {
			if (c - '0') {
				counts[i].second++;
			} else {
				counts[i].first++;
			}
		}
	}

	vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(sz + 1)));
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= n; ++j) {
			for (int k = 1; k <= sz; ++k) {
				dp[i][j][k] = dp[i][j][k - 1];
				if (i >= counts[k - 1].first and j >= counts[k - 1].second) {
					dp[i][j][k] = max(dp[i][j][k], dp[i - counts[k - 1].first][j - counts[k - 1].second][k - 1] + 1);
				}
			}
		}
	}

	return dp[m][n][sz];
}

int main(int argc, char const *argv[]) {
	int sz;
	cin >> sz;
	vector<string> arr(sz);
	for (int i = 0; i <= sz - 1; ++i) {
		cin >> arr[i];
	}
	int m, n;
	cin >> m >> n;

	cout << findMaxForm(arr, m, n);

	return 0;
}