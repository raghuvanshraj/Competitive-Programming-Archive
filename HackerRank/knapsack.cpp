/**
 *    author:	vulkan
 *    created:	03.09.2019 07:16:37 PM
**/
#include <bits/stdc++.h>

using namespace std;

int unbounded_knapsack(int arr[], int n, int k) {
	int dp[n + 1][k + 1];
	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < k + 1; ++j) {
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < k + 1; ++j) {
			if (arr[i - 1] <= j) {
				dp[i][j] = max(arr[i - 1] + dp[i][j - arr[i - 1]], dp[i - 1][j]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[n][k];
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int arr[n];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		cout << unbounded_knapsack(arr, n, k) << endl;
	}

	return 0;
}