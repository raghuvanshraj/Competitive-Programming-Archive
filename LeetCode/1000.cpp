/**
 *    author:	vulkan
 *    created:	07.03.2020 10:54:34 PM
**/
#include <bits/stdc++.h>

using namespace std;

int mergeStones(vector<int> &stones, int k) {
	int n = stones.size();
	if (n == 1) {
		return 0;
	}

	vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0, INT_MAX}));

	for (int i = 0; i < n; ++i) {
		int curr_sum = 0;
		for (int j = i; j < n; ++j) {
			curr_sum += stones[j];
			dp[i][j].first = curr_sum;

			if (j - i + 1 == k) {
				dp[i][j].second = curr_sum;
			}
		}
	}

	for (int gap = k; gap < n; ++gap) {
		for (int j = gap; j < n; ++j) {
			int i = j - gap;

			if (dp[i][j - k + 1].second != INT_MAX) {
				dp[i][j].second = min({
					dp[i][j].second,
					dp[i][j].first + dp[i][j - k + 1].second
				});
			}

			if (i + k - 1 <= j and dp[i + k - 1][j].second != INT_MAX) {
				dp[i][j].second = min({
					dp[i][j].second,
					dp[i][j].first + dp[i + k - 1][j].second
				});
			}

			for (int l = i; l <= j; ++l) {
				if (j + l - i - k + 1 <= j and dp[l][j + l - i - k + 1].second != INT_MAX) {
					dp[i][j].second = min({
						dp[i][j].second,
						dp[i][j].first + dp[l][j + l - i - k + 1].second
					});
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int curr = (dp[i][j].second == INT_MAX) ? -1 : dp[i][j].second;
			cout << curr << ' ';
		}

		cout << endl;
	}

	return (dp[0][n - 1].second == INT_MAX) ? -1 : dp[0][n - 1].second;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> stones(n);
	for (int i = 0; i < n; ++i) {
		cin >> stones[i];
	}

	int k;
	cin >> k;

	cout << mergeStones(stones, k);

	return 0;
}