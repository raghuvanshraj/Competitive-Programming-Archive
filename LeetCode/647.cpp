/**
 *    author:	vulkan
 *    created:	13.01.2022 07:24:14 PM
**/
#include <bits/stdc++.h>

using namespace std;

int countSubstrings(string s) {
	int n = s.size();
	vector<vector<bool>> dp(n, vector<bool>(n));
	for (int i = 0; i <= n - 1; ++i) {
		dp[i][i] = true;
	}
	for (int i = 0, j = 1; j <= n - 1; ++i, ++j) {
		if (s[i] == s[j]) {
			dp[i][j] = true;
		}
	}

	for (int g = 2; g <= n - 1; ++g) {
		for (int i = 0, j = g; j <= n - 1; ++i, ++j) {
			if (s[i] == s[j]) {
				dp[i][j] = dp[i + 1][j - 1];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = i; j <= n - 1; ++j) {
			ans += dp[i][j];
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	cout << countSubstrings(s);

	return 0;
}