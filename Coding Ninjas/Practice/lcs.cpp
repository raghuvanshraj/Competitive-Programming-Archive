#include <bits/stdc++.h>

using namespace std;

int LCS(string s1, string s2) {
	int lcs[s1.length()+1][s2.length()+1];
	memset(lcs, 0, sizeof(int) * (s1.length()+1) * (s2.length()+1));

	for (int i = 1; i < s1.length()+1; ++i) {
		for (int j = 1; j < s2.length()+1; ++j) {
			if (s1[i-1] == s2[j-1]) {
				lcs[i][j] = lcs[i-1][j-1]+1;
			} else {
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
			}
		}
	}

	return lcs[s1.length()][s2.length()];
}

int main(int argc, char const *argv[]) {
	string s1, s2;
	cin >> s1 >> s2;
	cout << LCS(s1, s2);
	return 0;
}