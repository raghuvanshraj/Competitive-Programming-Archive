#include <bits/stdc++.h>

using namespace std;

int calculateMinimumHP(vector<vector<int>> &matrix) {
	int m = matrix.size();
	int n = matrix[0].size();
	vector<vector<int>> dp(m);
	for (int i = 0; i < m; ++i) {
		dp[i] = vector<int>(n);
	}

	for (int i = m-1; i >= 0; i--) {
		for (int j = n-1; j >= 0; j--) {
			if (i == m-1 and j == n-1) {
				dp[i][j] = max(1, 1 - matrix[i][j]);
			} else if (i == m-1) {
				dp[i][j] = max(dp[i][j+1] - matrix[i][j], 1);
			} else if (j == n-1) {
				dp[i][j] = max(dp[i+1][j] - matrix[i][j], 1);
			} else {
				dp[i][j] = max(
						min(dp[i+1][j], dp[i][j+1]) - matrix[i][j], 1
					);
			}
		}
	}

	return dp[0][0];
}

int main(int argc, char const *argv[]) {
	int m,n;
	cin >> m >> n;
	vector<vector<int>> matrix(m);
	for (int i = 0; i < m; ++i) {
		matrix[i] = vector<int>(n);
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}

	cout << calculateMinimumHP(matrix);
	return 0;
}