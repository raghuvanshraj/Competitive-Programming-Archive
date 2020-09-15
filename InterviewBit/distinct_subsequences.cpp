#include <bits/stdc++.h>

using namespace std;

int numDistinct(string s, string t) {
	int n = s.size(), m = t.size();
	int dp[n+1][m+1];
	for (int i = 0; i < n+1; ++i) {
		for (int j = 0; j < m+1; ++j) {
			if (j == 0) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = 0;
			}
		}
	}

	for (int i = 1; i < n+1; ++i) {
		for (int j = 1; j < m+1; ++j) {
			if (s[i-1] == t[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			}

			dp[i][j] += dp[i-1][j];
		}
	}

	return dp[n][m];
}

int main(int argc, char const *argv[]) {
	string s,t;
	cin >> s >> t;
	cout << numDistinct(s,t);
	
	return 0;
}