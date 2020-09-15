#include <bits/stdc++.h>

using namespace std;

int maxcoin(vector<int> &arr_coins) {
	int n = arr_coins.size();
	int dp[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		dp[i][i] = arr_coins[i];
	}

	for (int gap = 1; gap < n; ++gap) {
		for (int i = 0; i < n-gap; ++i) {
			int j = i + gap;

			int x = dp[i+2][j], y = dp[i+1][j-1], z = dp[i][j-2];

			dp[i][j] = max(arr_coins[i] + min(x,y), arr_coins[j] + min(y,z));
		}
	}

	return dp[0][n-1];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr_coins(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr_coins[i];
	}

	cout << maxcoin(arr_coins);
	
	return 0;
}