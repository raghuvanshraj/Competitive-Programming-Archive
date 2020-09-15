/**
 *    author:	vulkan
 *    created:	27.08.2019 12:30:09 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool is_possible(int s[], int n, int m) {
	bool dp[n][n][m + 1];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m + 1; ++k) {
				if (i == j) {
					dp[i][j][k] = (s[i] <= k);
				} else {
					dp[i][j][k] = false;
				}
			}
		}
	}

	for (int gap = 1; gap < n; ++gap) {
		for (int i = 0, j = gap; j < n; ++i, ++j) {
			for (int k = 1; k < m + 1; ++k) {
				for (int idx = i; idx < j + 1; ++idx) {
					if (s[idx] <= k) {
						if (idx == i) {
							dp[i][j][k] = not dp[i + 1][j][k - s[idx]];
						} else if (idx == j) {
							dp[i][j][k] = not dp[i][j - 1][k - s[idx]];
						} else {
							dp[i][j][k] = not (dp[i][idx - 1][k - s[idx]] or dp[idx + 1][j][k - s[idx]]);
						}
					}
				}
			}
		}
	}

	return dp[0][n - 1][m];
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		int s[n];
		for (int i = 0; i < n; ++i) {
			cin >> s[i];
		}

		string ans = is_possible(s, n, m) ? "Little Deepu" : "Kate";
		cout << ans << endl;
	}

	return 0;
}