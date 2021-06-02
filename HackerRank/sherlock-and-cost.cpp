/**
 *    author:    raghuvanshraj
 *    created:   13.09.2019 10:19:27 PM
**/
#include <bits/stdc++.h>
#define MAX_ELT 101

using namespace std;

int max_cost(int arr[], int n) {
	int dp[n][2];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i < n; ++i) {
		dp[i][0] = abs(arr[i - 1] - 1) + dp[i - 1][1];
		dp[i][1] = max(
		               abs(arr[i - 1] - arr[i]) + dp[i - 1][1],
		               abs(arr[i] - 1) + dp[i - 1][0]
		           );
	}

	return max(dp[n - 1][0], dp[n - 1][1]);
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		cout << max_cost(arr, n) << endl;
	}

	return 0;
}
