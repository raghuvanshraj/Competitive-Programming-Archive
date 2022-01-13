/**
 *    author:	vulkan
 *    created:	13.01.2022 07:39:05 PM
**/
#include <bits/stdc++.h>
#define N 40001

using namespace std;

int idx(int x) {
	return (x + N) % N;
}

int findTargetSumWays(vector<int> &arr, int t) {
	int sum = accumulate(arr.begin(), arr.end(), 0);
	int n = arr.size();
	vector<vector<int>> dp(n + 1, vector<int>(N));
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int x = -sum; x <= sum; ++x) {
			dp[i][idx(x)] = dp[i - 1][idx(x - arr[i - 1])] + dp[i - 1][idx(x + arr[i - 1])];
		}
	}

	return dp[n][idx(t)];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}
	int t;
	cin >> t;

	cout << findTargetSumWays(arr, t);

	return 0;
}