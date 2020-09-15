#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull coinChange(int *coins, int n, int m) {
	ull *change = new ull[n+1]();
	change[0] = 1;

	for (int i = 0; i < m; ++i) {
		for (int j = coins[i]; j < n+1; ++j) {
			change[j] += change[j-coins[i]];
		}
	}

	return change[n];
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