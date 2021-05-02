/**
 *    author:	vulkan
 *    created:	05.03.2020 02:13:17 PM
**/
#include <bits/stdc++.h>

using namespace std;

int minDistance(string word1, string word2) {
	int n = word1.size(), m = word2.size();
	vector<vector<int>> dp(n + 1, vector<int>(m + 1));

	for (int i = 0; i < n + 1; ++i) {
		dp[i][0] = i;
	}

	for (int i = 0; i < m + 1; ++i) {
		dp[0][i] = i;
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < m + 1; ++j) {
			if (word1[i - 1] != word2[j - 1]) {
				dp[i][j] = min({
					dp[i - 1][j],
					dp[i][j - 1],
					dp[i - 1][j - 1]
				}) + 1;
			} else {
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}

	return dp[n][m];
}

int main(int argc, char const *argv[]) {
	string word1, word2;
	cin >> word1 >> word2;

	cout << minDistance(word1, word2);

	return 0;
}