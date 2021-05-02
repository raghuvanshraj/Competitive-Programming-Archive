/**
 *    author:	vulkan
 *    created:	22.06.2020 08:39:21 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

typedef long long LL;

using namespace std;

int numRollsToTarget(int d, int f, int target) {
	vector<vector<LL>> dp(d + 1, vector<LL>(target + 1));
	dp[0][0] = 1LL;
	for (int i = 1; i <= d; ++i) {
		for (int j = 1; j <= target; ++j) {
			for (int k = 1; k <= min(f, j); ++k) {
				dp[i][j] += dp[i - 1][j - k];
				dp[i][j] %= MOD;
			}
		}
	}

	return dp[d][target];
}

int main(int argc, char const *argv[]) {
	int d, f, target;
	cin >> d >> f >> target;

	cout << numRollsToTarget(d, f, target);

	return 0;
}