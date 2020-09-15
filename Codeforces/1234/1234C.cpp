/**
 *    author:	vulkan
 *    created:	18.10.2019 05:20:54 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		int dp[n][2];
		for (int i = 0; i < n; ++i) {
			dp[i][0] = -1;
			dp[i][1] = -1;
		}

		dp[0][0] = (s1[0] < '3') ? 2 : 4;
		dp[0][1] = (s2[0] >= '3' and dp[0][0] == 4) ? 6 : -1;
		for (int i = 1; i < n; ++i) {
			if (s1[i] >= '3' and s2[i] >= '3') {
				if (dp[i - 1][0] == 2 or dp[i - 1][0] == 3) {
					dp[i][0] = 4;
					dp[i][1] = 6;
				} else if (dp[i - 1][1] == 2 or dp[i - 1][1] == 6) {
					dp[i][0] = 3;
					dp[i][1] = 5;
				} else {
					dp[i][0] = -1;
					dp[i][1] = -1;
					break;
				}
			} else if (s1[i] < '3' and s2[i] < '3') {
				if (dp[i - 1][0] == 2 or dp[i - 1][0] == 3) {
					dp[i][0] = 2;
					dp[i][1] = -1;
				} else if (dp[i - 1][1] == 2 or dp[i - 1][1] == 6) {
					dp[i][0] = -1;
					dp[i][1] = 2;
				}
			} else {
				if (s1[i] < '3') {
					if (dp[i - 1][0] == 2 or dp[i - 1][0] == 3) {
						dp[i][0] = 2;
					} else {
						dp[i][0] = -1;
					}

					dp[i][1] = -1;
				} else {
					if (dp[i - 1][1] == 2 or dp[i - 1][1] == 6) {
						dp[i][1] = 2;
					} else {
						dp[i][1] = -1;
					}

					dp[i][0] = -1;
				}
			}
		}

		if (dp[n - 1][1] == 2 or dp[n - 1][1] == 6) {
			cout << "YES";
		} else {
			cout << "NO";
		}

		cout << endl;
	}

	return 0;
}