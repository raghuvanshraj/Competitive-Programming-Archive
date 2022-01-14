/**
 *    author:	vulkan
 *    created:	14.01.2022 12:40:46 PM
**/
#include <bits/stdc++.h>

using namespace std;

int rob(vector<int> &arr) {
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(2));
	for (int i = 0; i <= n - 1; ++i) {
		dp[i][1] = arr[i];
	}
	for (int i = 1; i <= n - 1; ++i) {
		dp[i][1] = max(dp[i][1], arr[i] + dp[i - 1][0]);
		dp[i][0] = max({
			dp[i][0],
			dp[i - 1][1],
			dp[i - 1][0]
		});
	}

	return max(dp[n - 1][0], dp[n - 1][1]);
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << rob(arr);

	return 0;
}