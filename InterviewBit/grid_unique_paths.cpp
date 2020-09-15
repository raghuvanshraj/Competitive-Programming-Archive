/**
 *    author:	vulkan
 *    created:	13.01.2020 02:07:25 PM
**/
#include <bits/stdc++.h>

using namespace std;

int uniquePaths(int n, int m) {
	int dp[n][m];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n; ++i) {
		dp[i][0] = 1;
	}

	for (int i = 0; i < m; ++i) {
		dp[0][i] = 1;
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	return dp[n - 1][m - 1];
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;

	cout << uniquePaths(n, m);

	return 0;
}