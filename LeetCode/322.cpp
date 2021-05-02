/**
 *    author:	vulkan
 *    created:	27.05.2020 10:51:55 AM
**/
#include <bits/stdc++.h>

using namespace std;

int coinChange(vector<int> &coins, int x) {
	int n = coins.size();
	vector<int> dp(x + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= x; ++i) {
		for (int j = 0; j <= n - 1; ++j) {
			if (coins[j] <= i) {
				if (dp[i - coins[j]] != INT_MAX) {
					dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
				}
			}
		}
	}

	return ((dp[x] == INT_MAX) ? -1 : dp[x]);
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> coins(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> coins[i];
	}
	int x;
	cin >> x;

	cout << coinChange(coins, x);

	return 0;
}