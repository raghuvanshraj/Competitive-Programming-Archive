#include <bits/stdc++.h>

using namespace std;

int min(int x, int y, int z) {
	return min(x, min(y, z));
}

int editDistance(string s1, string s2) {
	int minDistance[s1.length()+1][s2.length()+1];
	memset(minDistance, 0, sizeof(int) * (s1.length()+1) * (s2.length()+1));

	for (int i = 1; i < s1.length()+1; ++i) {
		minDistance[i][0] = i;
	}

	for (int i = 1; i < s2.length()+1; ++i) {
		minDistance[0][i] = i;
	}

	for (int i = 1; i < s1.length()+1; ++i) {
		for (int j = 1; j < s2.length()+1; ++j) {
			if (s1[i-1] == s2[j-1]) {
				minDistance[i][j] = minDistance[i-1][j-1];
			} else {
				minDistance[i][j] = min(minDistance[i-1][j-1],
										minDistance[i][j-1],
										minDistance[i-1][j]) + 1;
			}
		}
	}

	return minDistance[s1.length()][s2.length()];
}

int main(int argc, char const *argv[]) {
	string s1, s2;
	cin >> s1 >> s2;
	cout << editDistance(s1, s2);
	return 0;
}