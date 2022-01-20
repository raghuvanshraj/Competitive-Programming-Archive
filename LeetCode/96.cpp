/**
 *    author:	vulkan
 *    created:	18.01.2022 01:05:09 AM
**/
#include <bits/stdc++.h>

using namespace std;

int numTrees(int n) {
	vector<int> dp(n + 1);
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= i - 1; ++j) {
			dp[i] += dp[j] * dp[i - j - 1];
		}
	}

	return dp[n];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;

	cout << numTrees(n);

	return 0;
}