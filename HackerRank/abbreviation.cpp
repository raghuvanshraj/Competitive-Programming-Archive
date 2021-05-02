/**
 *    author:	vulkan
 *    created:	03.09.2019 10:59:12 AM
**/
#include <bits/stdc++.h>

using namespace std;

bool is_possible(string a, string b) {
	int n = a.size(), m = b.size();
	bool dp[n + 1][m + 1];
	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < m + 1; ++j) {
			dp[i][j] = false;
		}
	}

	dp[0][0] = true;
	for (int i = 1; i < n + 1; ++i) {
		if (a[i - 1] >= 97 and a[i - 1] <= 122) {
			dp[i][0] = dp[i - 1][0];
		}
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < m + 1; ++j) {
			if (a[i - 1] >= 97 and a[i - 1] <= 122) {
				if (a[i - 1] == b[j - 1] or a[i - 1] - 32 == b[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] or dp[i - 1][j];
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			} else if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}

	return dp[n][m];
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	while (q--) {
		string a, b;
		cin >> a >> b;

		string ans = (is_possible(a, b)) ? "YES" : "NO";
		cout << ans << endl;
	}

	return 0;
}