#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	
	int n, m;
	cin >> n >> m;
	int *left = new int[n]();
	int *right = new int[n]();
	for (int i = 0; i < m; ++i) {
		
		int l, r;
		cin >> l >> r;
		left[l-1]++;
		right[r-1]++;
	}

	int *coins = new int[n]();
	coins[0] = left[0];
	for (int i = 1; i < n; ++i) {
		
		coins[i] = left[i] + coins[i-1] - right[i-1];
	}

	int *dp = new int[m+1]();
	for (int i = 0; i < n; ++i) {
		dp[coins[i]]++;
	}

	int *atleast = new int[m+1]();
	atleast[m] = dp[m];
	for (int i = m-1; i >= 0; --i) {
		
		atleast[i] = dp[i] + atleast[i+1];
	}

	int q;
	cin >> q;
	while (q--) {
		
		int x;
		cin >> x;
		if (x > m) {
			cout << "0\n";
			continue;
		}
		
		cout << atleast[x] << endl;
	}
	return 0;
}