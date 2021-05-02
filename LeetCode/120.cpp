/**
 *    author:	vulkan
 *    created:	27.05.2020 07:55:51 PM
**/
#include <bits/stdc++.h>

using namespace std;

int minimumTotal(vector<vector<int>> &arr) {
	int n = arr.size();
	if (n == 0) {
		return 0;
	}

	vector<int> dp(n, INT_MAX);
	dp[0] = arr[0][0];
	for (int i = 1; i <= n - 1; ++i) {
		for (int j = i; j >= 0; --j) {
			if (j > 0) {
				dp[j] = min(dp[j], dp[j - 1]);
			}
			dp[j] += arr[i][j];
		}
	}

	return *min_element(dp.begin(), dp.end());
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n));
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> arr[i][j];
		}
	}

	// for (int i = 0; i <= n-1; ++i) {
	// 	for (int j = 0; j <= i; ++j) {
	// 		cout << arr[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	cout << minimumTotal(arr);

	return 0;
}