#include <bits/stdc++.h>

using namespace std;

int isInterleave(string s1, string s2, string s3) {
	int s1_size = s1.size(), s2_size = s2.size();

	if (s1_size + s2_size != s3.size()) {
		return 0;
	}

	bool dp[s1_size+1][s2_size+1];

	for (int i = 0; i < s1_size+1; ++i) {
		for (int j = 0; j < s2_size+1; ++j) {
			dp[i][j] = false;

			if (i == 0 and j == 0) {
				dp[i][j] = true;
			} else if (i == 0 and s2[j-1] == s3[j-1]) {
				dp[i][j] = dp[i][j-1];
			} else if (j == 0 and s1[i-1] == s3[i-1]) {
				dp[i][j] = dp[i-1][j];
			} else {
				if (s3[i+j-1] == s2[j-1] and s3[i+j-1] == s1[i-1]) {
					dp[i][j] = dp[i-1][j] or dp[i][j-1];
				} else {
					if (s3[i+j-1] == s1[i-1]) {
						dp[i][j] = dp[i-1][j];
					} else if (s3[i+j-1] == s2[j-1]) {
						dp[i][j] = dp[i][j-1];
					}
				}
			}
		}
	}

	return dp[s1_size][s2_size];
}

int main(int argc, char const *argv[]) {
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;

	cout << isInterleave(s1,s2,s3);
	
	return 0;
}