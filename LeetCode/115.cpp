/**
 *    author:	vulkan
 *    created:	10.03.2020 11:02:35 AM
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll numDistinct(string s, string t) {
	int n = s.size(), m = t.size();

	vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0LL));
	for (int i = 0; i < n + 1; ++i) {
		dp[i][0] = (ll)1;
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j <= min(i, m); ++j) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = (ll)dp[i - 1][j - 1] + (ll)dp[i - 1][j];
			} else {
				dp[i][j] = (ll)dp[i - 1][j];
			}
		}
	}

	return dp[n][m];
}

int main(int argc, char const *argv[]) {
	string s, t;
	cin >> s >> t;

	cout << numDistinct(s, t);

	return 0;
}