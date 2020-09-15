#include <bits/stdc++.h>

using namespace std;

int uKnapSack(int *values, int *weights, int n, int w) {
	int uk[w+1];

	for (int i = 0; i < w+1; ++i) {
		for (int j = 0; j < n+1; ++j) {
			if (i == 0 or j == 0) {
				uk[i] = 0;
				continue;
			}

			if (weights[j-1] <= i) {
				uk[i] = max(uk[i], uk[i-weights[j-1]] + values[j-1]);
			}
		}
	}

	return uk[w];
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int *values = new int[n]();
		int *weights = new int[n]();

		int w;
		cin >> w;

		for (int i = 0; i < n; ++i) {
			cin >> values[i];
		}

		for (int i = 0; i < n; ++i) {
			cin >> weights[i];
		}

		cout << uKnapSack(values, weights, n, w) << endl;
	}
	return 0;
}