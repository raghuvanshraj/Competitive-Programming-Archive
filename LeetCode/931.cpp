/**
 *    author:	vulkan
 *    created:	27.05.2020 11:09:31 AM
**/
#include <bits/stdc++.h>

using namespace std;

int minFallingPathSum(vector<vector<int>> &arr) {
	int n = arr.size();
	int m = (n != 0) ? arr[0].size() : -1;
	if (m == -1) {
		return 0;
	}

	vector<vector<int>> dp(n, vector<int>(m));
	for (int i = 0; i <= m - 1; ++i) {
		dp[0][i] = arr[0][i];
	}

	for (int i = 1; i <= n - 1; ++i) {
		for (int j = 0; j <= m - 1; ++j) {
			int opt1 = (j < m - 1) ? dp[i - 1][j + 1] : INT_MAX;
			int opt2 = dp[i - 1][j];
			int opt3 = (j > 0) ? dp[i - 1][j - 1] : INT_MAX;

			dp[i][j] = min({opt1, opt2, opt3}) + arr[i][j];
		}
	}

	return *min_element(dp[n - 1].begin(), dp[n - 1].end());
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= m - 1; ++j) {
			cin >> arr[i][j];
		}
	}

	cout << minFallingPathSum(arr);

	return 0;
}