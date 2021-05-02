/**
 *    author:	vulkan
 *    created:	06.09.2019 08:02:30 PM
**/
#include <bits/stdc++.h>

using namespace std;

long find_subsequences(int arr[], int n, int k, int sum) {
	if (k > n) {
		return 0;
	}

	long dp[n + 1][k + 1][sum + 1];
	for (int i = 0; i < n + 1; ++i) {
		for (int j = 0; j < k + 1; ++j) {
			for (int l = 0; l < sum + 1; ++l) {
				dp[i][j][l] = 0;
			}
		}
	}

	for (int i = 0; i < n + 1; ++i) {
		dp[i][0][0] = 1;
	}

	for (int i = 1; i < n + 1; ++i) {
		for (int j = 1; j < min(i, k) + 1; ++j) {
			for (int l = 1; l < sum + 1; ++l) {
				if (arr[i - 1] <= l) {
					dp[i][j][l] = dp[i - 1][j - 1][l - arr[i - 1]] + dp[i - 1][j][l];
				} else {
					dp[i][j][l] = dp[i - 1][j][l];
				}
			}
		}
	}

	return dp[n][k][sum];
}

long k_subsequence(int arr[], int n, int k) {
	int sorted_arr[n];
	for (int i = 0; i < n; ++i) {
		sorted_arr[i] = arr[i];
	}

	sort(sorted_arr, sorted_arr + n);
	int sum = accumulate(sorted_arr, sorted_arr + k, 0);

	return find_subsequences(arr, n, k, sum);
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

		cout << k_subsequence(arr, n, k) << endl;
	}

	return 0;
}