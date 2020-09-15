/**
 *    author:	vulkan
 *    created:	19.10.2019 01:34:24 PM
**/
#include <bits/stdc++.h>

using namespace std;

int max_spending(vector<int> costs[], int k[], int n, int b) {
	int *dp = new int[b + 1]();

	for (int i = 0; i < k[0]; ++i) {
		if (costs[0][i] <= b) {
			dp[costs[0][i]] = 1;
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < k[i]; ++j) {
			for (int l = 0; l < b + 1; ++l) {
				if (dp[l] == i and l + costs[i][j] <= b) {
					dp[l + costs[i][j]] = i + 1;
				}
			}
		}
	}

	for (int i = b; i >= 0; --i) {
		if (dp[i] == n) {
			return i;
		}
	}

	return 0;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int b;
		cin >> b;
		int n;
		cin >> n;
		int k[n];
		for (int i = 0; i < n; ++i) {
			cin >> k[i];
		}

		vector<int> costs[n];
		for (int i = 0; i < n; ++i) {
			costs[i] = vector<int>(k[i]);
			for (int j = 0; j < k[i]; ++j) {
				cin >> costs[i][j];
			}
		}

		cout << max_spending(costs, k, n, b) << endl;
	}

	return 0;
}