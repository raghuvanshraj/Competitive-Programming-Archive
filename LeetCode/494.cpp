/**
 *    author:	vulkan
 *    created:	23.06.2020 08:14:31 PM
**/
#include <bits/stdc++.h>

using namespace std;

int findTargetSumWays(vector<int> &arr, int t) {
	int n = arr.size();
	int s = accumulate(arr.begin(), arr.end(), 0);
	vector<vector<int>> dp(2 * s + 1, vector<int>(n + 1));
	for (int i = 0; i <= n; ++i) {
		dp[0][i] = 1;
	}

	for (int j = 1; j <= n; ++j) {
		for (int i = -s; i <= s; ++i) {

		}
	}

	// for (int i = 0; i <= s; ++i) {
	// 	for (int j = 0; j <= n; ++j) {
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	return ((t >= 0) ? dp[t][n] : dp[2 * s + 1 + t][n]);
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