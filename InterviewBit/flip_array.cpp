#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int> &arr) {
	int sum = accumulate(arr.begin(), arr.end(), 0);
	int n = arr.size();
	int wt = sum/2;
	int **dp = new int*[n+1]();
	for (int i = 0; i < n+1; ++i) {
		dp[i] = new int[wt+1]();
		for (int j = 0; j < wt+1; ++j) {
			if (j == 0) {
				dp[i][j] = 0;
			} else {
				dp[i][j] = INT_MAX;
			}
		}
	}

	for (int i = 1; i < n+1; ++i) {
		for (int j = 1; j < wt+1; ++j) {
			if (j - arr[i-1] >= 0 and dp[i-1][j-arr[i-1]] != INT_MAX) {
				dp[i][j] = min(dp[i-1][j], 1 + dp[i-1][j-arr[i-1]]);
			}
		}
	}
	
	for (int i = wt; i >= 0; --i) {
		int min_items = INT_MAX;
		for (int j = 0; j < n+1; ++j) {
			min_items = min(min_items, dp[j][i]);
		}
		if (min_items != INT_MAX) {
			return min_items;
		}
	}
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << solve(arr);
	return 0;
}