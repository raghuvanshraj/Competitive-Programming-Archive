/**
 *    author:	vulkan
 *    created:	05.03.2020 02:31:28 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool isMatch(string s, string p) {
	int n = s.size(), m = p.size();
	vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));

	dp[0][0] = true;
	for (int i = 2; i <= m; ++i) {
		if (p[i - 1] == '*') {
			dp[0][i] = dp[0][i - 2];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (p[j - 1] == '.' or p[j - 1] == '*') {
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 2];
					if (p[j - 2] == '.' or s[i - 1] == p[j - 2]) {
						dp[i][j] = dp[i][j] or dp[i - 1][j];
					}
				} else {
					dp[i][j] = dp[i - 1][j - 1];
				}
			} else {
				dp[i][j] = dp[i - 1][j - 1] and (s[i - 1] == p[j - 1]);
			}
		}
	}

	return dp[n][m];
}

int main(int argc, char const *argv[]) {
	string s, p;
	cin >> s >> p;

	cout << isMatch(s, p);

	return 0;
}