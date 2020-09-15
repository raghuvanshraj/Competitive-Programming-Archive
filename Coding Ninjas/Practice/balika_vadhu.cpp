#include <bits/stdc++.h>

using namespace std;

int maxHappiness(string s1, string s2, int k) {
	int dp[s1.length()+1][s2.length()+1][k+1];
	memset(dp, 0, sizeof(int) * (s1.length()+1) * (s2.length()+1) * (k+1));

	for (int i = 0; i < s1.length()+1; ++i) {
		for (int j = 0; j < s2.length()+1; ++j) {
			for (int l = 1; l < k+1; ++l) {
				if (i == 0 or j == 0) {
					dp[i][j][l] = INT_MIN;
					continue;
				}

				if (s1[i-1] == s2[j-1]) {
					dp[i][j][l] = max(dp[i-1][j-1][l-1] + s1[i-1], dp[i-1][j-1][l]);
				} else {
					dp[i][j][l] = max(dp[i-1][j][l], dp[i][j-1][l]);
				}
			}
		}
	}

	return max(dp[s1.length()][s2.length()][k], 0);
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;
		int k;
		cin >> k;

		cout << maxHappiness(s1, s2, k) << endl;
	}
	return 0;
}