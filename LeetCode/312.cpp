/**
 *    author:	vulkan
 *    created:	08.03.2020 03:18:43 PM
**/
#include <bits/stdc++.h>

using namespace std;

int maxCoins(vector<int> &nums) {
	int n = nums.size();
	if (n == 0) {
		return 0;
	}

	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i) {
		int left = (i > 0) ? nums[i - 1] : 1;
		int right = (i < n - 1) ? nums[i + 1] : 1;
		dp[i][i] = left * nums[i] * right;
	}

	for (int gap = 1; gap < n; ++gap) {
		for (int j = gap; j < n; ++j) {
			int i = j - gap;
			int left = (i > 0) ? nums[i - 1] : 1;
			int right = (j < n - 1) ? nums[j + 1] : 1;
			for (int l = i; l <= j; ++l) {
				if (l == i) {
					dp[i][j] = max({
						dp[i][j],
						left * nums[l] * right + dp[l + 1][j]
					});
				} else if (l == j) {
					dp[i][j] = max({
						dp[i][j],
						left * nums[l] * right + dp[i][l - 1]
					});
				} else {
					dp[i][j] = max({
						dp[i][j],
						left * nums[l] * right + dp[i][l - 1] + dp[l + 1][j]
					});
				}
			}
		}
	}

	return dp[0][n - 1];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	cout << maxCoins(nums);

	return 0;
}