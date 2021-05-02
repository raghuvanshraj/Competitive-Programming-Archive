/**
 *    author:    raghuvanshraj
 *    created:    05.03.2020 02:35:15 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool isMatch(string s, string p) {
	int n = s.size(), m = p.size();
	bool dp[n+1][m+1];
	for (int i = 0; i < n+1; ++i) {
		for (int j = 0; j < m+1; ++j) {
			dp[i][j] = false;
		}
	}

	dp[0][0] = true;
	for (int j = 1; j < m+1; ++j) {
		if (p[j-1] == '*') {
			dp[0][j] = dp[0][j-1];
		}
	}

	for (int i = 1; i < n+1; ++i) {
		for (int j = 1; j < m+1; ++j) {
			if (p[j-1] == '*') {
				dp[i][j] = dp[i-1][j] or dp[i][j-1];
			} else if (p[j-1] == '?' or s[i-1] == p[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = false;
			}
		}
	}

	return dp[n][m];
}

int main(int argc, char const *argv[]) {    
	string s,p;
	cin >> s >> p;

	cout << isMatch(s,p);
	
	return 0;
}