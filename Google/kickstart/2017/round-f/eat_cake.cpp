/**
 *    author:	vulkan
 *    created:	01.11.2019 07:09:01 PM
**/
#include <bits/stdc++.h>

using namespace std;

int eat_cake(int n) {
	int dp[n + 1];
	for (int i = 0; i < n + 1; ++i) {
		dp[i] = INT_MAX;
	}

	dp[0] = 0;
	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j * j <= i; ++j) {
			dp[i] = min(dp[i], dp[i - (j * j)] + 1);
		}
	}

	return dp[n];
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int n;
		cin >> n;
		cout << "Case #" << t + 1 << ": " << eat_cake(n) << endl;
	}

	return 0;
}