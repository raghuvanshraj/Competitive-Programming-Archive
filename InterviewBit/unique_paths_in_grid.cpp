#include <bits/stdc++.h>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &grid) {
	int n = grid.size(), m = grid[0].size();
	int dp[n][m];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			dp[i][j] = 0;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 1) {
				continue;
			}

			if (i == 0 and j == 0) {
				dp[i][j] = 1;
			} else if (i == 0) {
				dp[i][j] = dp[i][j-1];
			} else if (j == 0) {
				dp[i][j] = dp[i-1][j];
			} else {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
	}

	return dp[n-1][m-1];
}

int main(int argc, char const *argv[]) {
	int n,m;
	cin >> n >> m;
	vector<vector<int>> grid(n);
	for (int i = 0; i < n; ++i) {
		grid[i] = vector<int>(m);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
		}
	}

	cout << uniquePathsWithObstacles(grid);
	
	return 0;
}