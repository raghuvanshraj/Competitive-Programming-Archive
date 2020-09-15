#include <bits/stdc++.h>

using namespace std;

long farida(int *coins, int n) {

	long *output = new long[n]();
	output[0] = coins[0];
	output[1] = max(coins[0], coins[1]);

	for (int i = 2; i < n; ++i) {
		
		output[i] = max(output[i-2] + coins[i], output[i-1]);
	}

	return output[n-1];
}

int main(int argc, char const *argv[]) {
	
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		
		int n;
		cin >> n;
		int *coins = new int[n]();
		for (int i = 0; i < n; ++i) {
			cin >> coins[i];
		}

		cout << "Case " << i+1 << ": " << farida(coins, n) << endl;
	}
	return 0;
}