#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int solve(int n, int s) {
	int **dp = new int*[n+1]();
	for (int i = 0; i < n+1; ++i) {
		dp[i] = new int[s+1]();
	}

	dp[0][0] = 1;

	for (int i = 1; i < n+1; ++i) {
		for (int j = 1; j < s+1; ++j) {
			dp[i][j] = 0;
			int start = 0, end = min(9,j);
			if (i == 1) {
				start = 1;
			}

			for (int k = start; k < end+1; ++k) {
				dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
			}
		}
	}

	return (dp[n][s] + MOD) % MOD;
}

int main(int argc, char const *argv[]) {
	int n,s;
	cin >> n >> s;
	cout << solve(n,s);
	return 0;
}