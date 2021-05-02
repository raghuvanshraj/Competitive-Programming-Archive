/**
 *    author:	vulkan
 *    created:	10.06.2020 11:43:57 AM
**/
#include <bits/stdc++.h>

using namespace std;

int calculateMinimumHP(vector<vector<int>> &matrix) {
	int n = matrix.size();
	if (n == 0) {
		return 0;
	}

	int m = matrix[0].size();
	if (m == 0) {
		return 0;
	}

	vector<vector<int>> dp(n, vector<int>(m));
	dp[n - 1][m - 1] = max(1, 1 - matrix[n - 1][m - 1]);
	for (int i = n - 2; i >= 0; --i) {
		dp[i][m - 1] = max(1, dp[i + 1][m - 1] - matrix[i][m - 1]);
	}
	for (int i = m - 2; i >= 0; --i) {
		dp[n - 1][i] = max(1, dp[n - 1][i + 1] - matrix[n - 1][i]);
	}

	for (int i = n - 2; i >= 0; --i) {
		for (int j = m - 2; j >= 0; --j) {
			int prev = min(dp[i + 1][j], dp[i][j + 1]);
			dp[i][j] = max(1, prev - matrix[i][j]);
		}
	}

	return dp[0][0];
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(m));
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= m - 1; ++j) {
			cin >> matrix[i][j];
		}
	}

	cout << calculateMinimumHP(matrix);

	return 0;
}