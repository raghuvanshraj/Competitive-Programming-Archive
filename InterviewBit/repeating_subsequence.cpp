#include <bits/stdc++.h>

using namespace std;

int anytwo(string s) {
	int n = s.size();
	int dp[n+1][n+1];
	for (int i = 0; i < n+1; ++i) {
		for (int j = 0; j < n+1; ++j) {
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i < n+1; ++i) {
		for (int j = 1; j < n+1; ++j) {
			if (s[i-1] == s[j-1] and i != j) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	if (dp[n][n] >= 2) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;
	cout << anytwo(s);
	
	return 0;
}