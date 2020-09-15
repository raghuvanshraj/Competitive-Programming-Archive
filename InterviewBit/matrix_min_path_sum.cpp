#include <bits/stdc++.h>

using namespace std;

int minPathSum(vector<vector<int>> &matrix) {
	int n = matrix.size();
	int **dp = new int*[n]();
	for (int i = 0; i < n; ++i) {
		dp[i] = new int[n]();
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j] = INT_MAX;
			if (i == 0 and j == 0) {
				dp[i][j] = matrix[i][j];
			} else if (i == 0) {
				dp[i][j] = dp[i][j-1] + matrix[i][j];
			} else if (j == 0) {
				dp[i][j] = dp[i-1][j] + matrix[i][j];
			} else {
				dp[i][j] = min({dp[i-1][j],
							    dp[i][j-1]}) + matrix[i][j];
			}
		}
	}

	// cout << n << endl;

	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	return dp[n-1][n-1];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<vector<int>> matrix(n);
	for (int i = 0; i < n; ++i) {
		matrix[i] = vector<int>(n);
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}

	cout << minPathSum(matrix);
	return 0;
}