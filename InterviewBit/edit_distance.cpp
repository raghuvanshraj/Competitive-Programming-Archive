#include <bits/stdc++.h>

using namespace std;

int minDistance(string a, string b) {
	int n = a.size();
	int m = b.size();
	int **dp = new int*[n+1]();
	for (int i = 0; i < n+1; ++i) {
		dp[i] = new int[m+1]();
	}

	for (int i = 0; i < n+1; ++i) {
		for (int j = 0; j < m+1; ++j) {
			if (i == 0) {
				dp[0][j] = j;
			} else if (j == 0) {
				dp[i][0] = i;
			} else if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = 1 + min({
					dp[i-1][j],
					dp[i-1][j-1],
					dp[i][j-1]
				});
			}
		}
	}

	return dp[n][m];
}

int main(int argc, char const *argv[]) {
	string a,b;
	cin >> a >> b;
	cout << minDistance(a,b);
	return 0;
}