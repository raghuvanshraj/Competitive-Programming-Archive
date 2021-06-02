/**
 *    author:	vulkan
 *    created:	02.09.2019 03:08:10 PM
**/
#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

long n_ways(int n, int k, int x) {
	if (n == 3) {
		return (x == 1) ? k - 1 : k - 2;
	}

	n--;
	long dp[n][2];
	for (int i = 0; i < n; ++i) {
		dp[i][0] = 0;
		dp[i][1] = 0;
	}

	for (int i = n - 1; i >= 0; --i) {
		if (i == n - 1) {
			dp[i][1] = (x == 1) ? 0 : 1;
			dp[i][0] = (x == 1) ? k - 1 : k - 2;
		} else {
			dp[i][1] = dp[i + 1][0];
			dp[i][0] = (((k - 1) * dp[i + 1][1]) % MOD + ((k - 2) * dp[i + 1][0]) % MOD) % MOD;
		}
	}

	return dp[0][1];
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, x;
	cin >> n >> k >> x;

	cout << n_ways(n, k, x);

	return 0;
}