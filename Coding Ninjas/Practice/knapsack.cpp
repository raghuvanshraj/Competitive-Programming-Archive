#include <bits/stdc++.h>

using namespace std;

int knapSack(int *values, int *weights, int n, int w) {
	int k[n+1][w+1];

	for (int i = 0; i < n+1; ++i) {
		for (int j = 0; j < w+1; ++j) {
			if (i == 0 or j == 0) {
				k[i][j] = 0;
				continue;
			}

			if (weights[i-1] > j) {
				k[i][j] = k[i-1][j];
			} else {
				k[i][j] = max(k[i-1][j-weights[i-1]] + values[i-1], 
								k[i-1][j]);
			}
		}
	}

	return k[n][w];
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int *weights = new int[n]();
		int *values = new int[n]();

		int w;
		cin >> w;

		for (int i = 0; i < n; ++i) {
			cin >> values[i];
		}

		for (int i = 0; i < n; ++i) {
			cin >> weights[i];
		}

		cout << knapSack(values, weights, n, w) << endl;
	}
	return 0;
}