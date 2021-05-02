/**
 *    author:	vulkan
 *    created:	15.05.2020 10:31:50 PM
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int splitArray(vector<int> &arr, int m) {
	int n = arr.size();
	vector<vector<pair<LL, LL>>> dp(n + 1, vector<pair<LL, LL>>(m + 1, { -1LL, 0LL}));

	dp[0][0] = {0LL, 0LL};

	for (int i = 0; i <= m; ++i) {
		dp[0][i] = {0LL, 0LL};
	}

	dp[1][1].first = dp[1][1].second = (LL)arr[0];
	for (int i = 2; i <= n; ++i) {
		dp[i][1].first = dp[i - 1][1].first + (LL)arr[i - 1];
		dp[i][1].second = dp[i][1].first;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 2; j <= min(i, m); ++j) {
			LL presum = (LL)arr[i - 1];
			for (int l = i - 1; l >= j - 1; --l) {
				if (dp[l][j - 1].first != -1) {
					LL curr = max(dp[l][j - 1].first, presum);
					if (dp[i][j].first == -1 or dp[i][j].first > curr) {
						dp[i][j].first = curr;
						dp[i][j].second = presum;
					}
				}

				presum += (LL)arr[l - 1];
			}
		}
	}

	return dp[n][m].first;
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << splitArray(arr, m);

	return 0;
}