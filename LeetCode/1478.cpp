/**
 *    author:	vulkan
 *    created:	16.08.2020 12:10:35 PM
**/
#include <bits/stdc++.h>

using namespace std;

int minDistance(vector<int> &houses, int k) {
	int n = houses.size();
	sort(houses.begin(), houses.end());

	vector<vector<int>> rng(n, vector<int>(n));
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = i; j <= n - 1; ++j) {
			for (int x = i; x <= j; ++x) {
				rng[i][j] += abs(houses[x] - houses[(i + j) / 2]);
			}
		}
	}

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
	for (int i = 1; i <= n; ++i) {
		dp[i][1] = rng[0][i - 1];
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= k; ++j) {
			for (int x = 1; x <= i - 1; ++x) {
				if (dp[x][j - 1] != INT_MAX) {
					dp[i][j] = min(dp[i][j], dp[x][j - 1] + rng[x][i - 1]);
				}
			}
		}
	}

	return dp[n][k];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> houses(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> houses[i];
	}
	int k;
	cin >> k;

	cout << minDistance(houses, k);

	return 0;
}