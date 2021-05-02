/**
 *    author:	vulkan
 *    created:	22.06.2020 08:35:46 PM
**/
#include <bits/stdc++.h>

using namespace std;

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n));
	dp[0][0] = 1;
	for (int i = 0; i <= m - 1; ++i) {
		dp[i][0] = 1;
	}
	for (int i = 0; i <= n - 1; ++i) {
		dp[0][i] = 1;
	}

	for (int i = 1; i <= m - 1; ++i) {
		for (int j = 1; j <= n - 1; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	return dp[m - 1][n - 1];
}

int main(int argc, char const *argv[]) {
	int m, n;
	cin >> m >> n;

	cout << uniquePaths(m, n);

	return 0;
}