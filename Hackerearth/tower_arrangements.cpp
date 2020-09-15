#include <bits/stdc++.h>

using namespace std;

int minSwaps(int *arr, int n) {
	int **dp = new int*[n]();
	for (int i = 0; i < n; ++i) {
		dp[i] = new int[2]();
	}

	dp[0][0] = (arr[0] == -1) ? 0 : 1;
	for (int i = 1; i < n; ++i) {
		dp[i][0] = dp[i-1][0];
		if (arr[i] == 1) {
			dp[i][0]++;
		}

		if (i == 1) {
			dp[i][1] = dp[i-1][0];
		} else {
			dp[i][1] = min(
					dp[i-1][1], dp[i-1][0]
				);
		}

		if (arr[i] == -1) {
			dp[i][1]++;
		}
	}

	return dp[n-1][1];
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int *arr = new int[n]();
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		cout << minSwaps(arr, n) << endl;
	}
	return 0;
}