#include <bits/stdc++.h>

using namespace std;

int minFare(int **fare, int n, int m) {
	int **dp = new int*[n]();
	for (int i = 0; i < n; ++i) {
		dp[i] = new int[m]();
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == 0) {
				dp[i][j] = fare[i][j];
				continue;
			}

			if (j == 0) {
				dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + fare[i][j];
			} else if (j == m-1) {
				dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + fare[i][j];
			} else {
				dp[i][j] = min(dp[i-1][j],
							min(dp[i-1][j-1],
								dp[i-1][j+1])) + fare[i][j];
			}
		}
	}

	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < m; ++j) {
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	int minimumFare = INT_MAX;
	for (int i = 0; i < m; ++i) {
		minimumFare = min(minimumFare, dp[n-1][i]);
	}

	return minimumFare;
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	int **fare = new int*[n]();
	for (int i = 0; i < n; ++i) {
		fare[i] = new int[m]();
		for (int j = 0; j < m; ++j) {
			cin >> fare[i][j];
		}
	}

	cout << minFare(fare, n, m);
	return 0;
}