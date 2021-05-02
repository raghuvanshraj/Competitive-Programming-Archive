/**
 *    author:	vulkan
 *    created:	27.05.2020 06:30:11 PM
**/
#include <bits/stdc++.h>

using namespace std;

int numSquares(int n) {
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; ++i) {
		dp[i] = i;
		for (int j = 1; j * j <= i; ++j) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	return dp[n];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;

	cout << numSquares(n);

	return 0;
}