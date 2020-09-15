#include <bits/stdc++.h>

using namespace std;

int egg_dropping(int n, int k) {
	int dp[n+1][k+1];
	for (int i = 0; i < n+1; ++i) {
		for (int j = 0; j < k+1; ++j) {
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i < n+1; ++i) {
		dp[i][1] = 1;
	}

	for (int i = 0; i < k+1; ++i) {
		dp[1][i] = i;
	}

	for (int i = 2; i < n+1; ++i) {
		for (int j = 2; j < k+1; ++j) {
			dp[i][j] = INT_MAX;
			for (int x = 1; x < j+1; ++x) {
				dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][x-1], dp[i][j-x]));
			}
		}
	}

	return dp[n][k];
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n,k;
		cin >> k >> n;

		cout << egg_dropping(n,k) << endl;
	}
	
	return 0;
}