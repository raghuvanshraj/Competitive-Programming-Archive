/**
 *    author:	vulkan
 *    created:	21.08.2020 05:40:25 PM
**/
#include <bits/stdc++.h>

using namespace std;

int minDifficulty(vector<int> &jobs, int d) {
	int n = jobs.size();
	vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX)), rng(n, vector<int>(n));
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = i; j <= n - 1; ++j) {
			if (i == j) {
				rng[i][j] = jobs[i];
			} else {
				rng[i][j] = max(rng[i][j - 1], jobs[j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		dp[i][1] = rng[0][i - 1];
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= min(i, d); ++j) {
			for (int x = 1; x <= i - 1; ++x) {
				if (dp[x][j - 1] != INT_MAX) {
					dp[i][j] = min(dp[i][j], dp[x][j - 1] + rng[x][i - 1]);
				}
			}
		}
	}

	return dp[n][d] != INT_MAX ? dp[n][d] : -1;
}

int main(int argc, char const *argv[]) {
	int n, d;
	cin >> n >> d;
	vector<int> jobs(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> jobs[i];
	}

	cout << minDifficulty(jobs, d);

	return 0;
}