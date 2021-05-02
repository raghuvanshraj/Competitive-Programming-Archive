/**
 *    author:	vulkan
 *    created:	27.05.2020 05:06:35 PM
**/
#include <bits/stdc++.h>

using namespace std;

int minSteps(int n) {
	if (n == 1) {
		return 0;
	}

	vector<int> dp(n + 1, 0);
	for (int i = 2; i <= n; ++i) {
		dp[i] = i;
		for (int j = i - 1; j >= 1; --j) {
			if (i % j == 0) {
				dp[i] = dp[j] + i / j;
			}
		}
	}

	return dp[n];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;

	cout << minSteps(n);

	return 0;
}