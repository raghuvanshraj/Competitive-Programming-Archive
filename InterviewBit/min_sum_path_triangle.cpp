#include <bits/stdc++.h>

using namespace std;

int minimumTotal(vector<vector<int>> &triangle) {
	vector<vector<int>> dp(triangle);
	int n = dp.size();
	for (int i = 1; i < n; ++i) {
		int m = dp[i].size();
		for (int j = 0; j < m; ++j) {
			if (j == 0) {
				dp[i][j] += dp[i-1][j];
			} else if (j == m-1) {
				dp[i][j] += dp[i-1][j-1];
			} else {
				dp[i][j] += min(dp[i-1][j], dp[i-1][j-1]);
			}
		}
	}

	int min_path = INT_MAX;
	int m = dp[n-1].size();
	for (int i = 0; i < m; ++i) {
		min_path = min(min_path, dp[n-1][i]);
	}

	return min_path;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<vector<int>> triangle(n);
	for (int i = 0; i < n; ++i) {
		triangle[i] = vector<int>(i+1);
		for (int j = 0; j < i+1; ++j) {
			cin >> triangle[i][j];
		}
	}

	cout << minimumTotal(triangle);
	
	return 0;
}