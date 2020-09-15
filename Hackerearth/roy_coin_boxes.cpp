/**
 *    author:	vulkan
 *    created:	28.08.2019 10:28:13 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int *left = new int[n]();
	int *right = new int[n]();
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		left[l - 1]++;
		right[r - 1]++;
	}

	int *coins = new int[n]();
	coins[0] = left[0];
	int *dp = new int[m + 1]();
	for (int i = 0; i < n; ++i) {
		coins[i] = coins[i - 1] + left[i] - right[i - 1];
		dp[coins[i]]++;
	}

	int *atleast = new int[m + 1]();
	atleast[m] = dp[m];
	for (int i = m - 1; i >= 0; i--) {
		atleast[i] = dp[i] + atleast[i + 1];
	}

	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		if (x > m) {
			cout << "0\n";
		} else {
			cout << atleast[x] << endl;
		}
	}

	return 0;
}