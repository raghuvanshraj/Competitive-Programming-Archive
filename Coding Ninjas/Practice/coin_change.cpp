#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull coinChange(int *coins, int n, int m) {
	ull **change = new ull*[n+1]();
	for (int i = 0; i < n+1; ++i) {
		change[i] = new ull[m]();
	}
	for (int i = 0; i < m; ++i) {
		change[0][i] = 1;
	}

	for (int i = 1; i < n+1; ++i) {
		for (int j = 0; j < m; ++j) {
			ull x = (i >= coins[j]) ? change[i-coins[j]][j] : 0;
			ull y = (j >= 1) ? change[i][j-1] : 0;

			change[i][j] = x + y;
		}
	}

	// for (int i = 0; i < n+1; ++i) {
	// 	for (int j = 0; j < m; ++j) {
	// 		cout << change[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	return change[n][m-1];
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	int *coins = new int[m]();
	for (int i = 0; i < m; ++i) {
		cin >> coins[i];
	}

	cout << coinChange(coins, n, m);
	return 0;
}