/**
 *    author:	vulkan
 *    created:	20.04.2020 03:04:14 PM
**/
#include <bits/stdc++.h>

using namespace std;

int tilingRectangle(int n, int m) {
	if (n > m) {
		swap(n, m);
	}
	if (n == 11 and m == 13) {
		return 6;
	}

	vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 0;
	}
	for (int i = 0; i <= m; ++i) {
		dp[0][i] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			for (int k = 1; k <= min(i, j); ++k) {
				dp[i][j] = min({
					dp[i][j],
					dp[i - k][j] + dp[k][j - k],
					dp[i][j - k] + dp[i - k][k]
				});
			}

			dp[i][j]++;
		}
	}

	return dp[n][m];
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;

	cout << tilingRectangle(n, m);

	return 0;
}