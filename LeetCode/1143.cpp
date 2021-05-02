/**
 *    author:	vulkan
 *    created:	27.04.2020 02:20:08 PM
**/
#include <bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string s, string t) {
	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max({
					dp[i - 1][j],
					dp[i][j - 1]
				});
			}
		}
	}

	return dp[n][m];
}

int main(int argc, char const *argv[]) {
	string s, t;
	cin >> s >> t;

	cout << longestCommonSubsequence(s, t);

	return 0;
}