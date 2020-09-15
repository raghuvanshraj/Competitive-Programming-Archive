#include <bits/stdc++.h>

using namespace std;

int rodCutting(int *prices, int n) {
	int maxValue[n+1];
	memset(maxValue, 0, sizeof(int) * (n+1));

	for (int i = 1; i < n+1; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (i >= j) {
				maxValue[i] = max(maxValue[i], prices[j-1] + maxValue[i-j]);
			}
		}
	}

	return maxValue[n];
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int *prices = new int[n]();

		for (int i = 0; i < n; ++i) {
			cin >> prices[i];
		}

		cout << rodCutting(prices, n) << endl;
	}
	return 0;
}