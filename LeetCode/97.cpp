/**
 *    author:	vulkan
 *    created:	09.03.2020 09:42:55 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
	int n = s1.size(), m = s2.size(), k = s3.size();
	if (k != n + m) {
		return false;
	}

	vector<vector<vector<bool>>> dp(n + 1, vector<vector<bool>>(m + 1, vector<bool>(k + 1)));

	dp[0][0][0] = true;
	for (int i = 1; i < n + 1; ++i) {
		if (s1[i - 1] == s3[i - 1]) {
			dp[i][0][i] = true;
		} else {
			break;
		}
	}

	for (int i = 1; i < m + 1; ++i) {
		if (s2[i - 1] == s3[i - 1]) {
			dp[0][i][i] = true;
		} else {
			break;
		}
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < m + 1; ++j) {
			if (s1[i - 1] == s3[i + j - 1] and s2[j - 1] == s3[i + j - 1]) {
				dp[i][j][i + j] = dp[i - 1][j][i + j - 1] or dp[i][j - 1][i + j - 1];
			} else {
				if (s1[i - 1] == s3[i + j - 1]) {
					dp[i][j][i + j] = dp[i - 1][j][i + j - 1];
				} else if (s2[j - 1] == s3[i + j - 1]) {
					dp[i][j][i + j] = dp[i][j - 1][i + j - 1];
				}
			}
		}
	}

	return dp[n][m][k];
}

int main(int argc, char const *argv[]) {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	cout << isInterleave(s1, s2, s3);

	return 0;
}