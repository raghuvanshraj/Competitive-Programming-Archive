#include <bits/stdc++.h>

using namespace std;

int maxGold(int **gold, int n, int m) {
	int **table = new int*[n]();
	for (int i = 0; i < m; ++i) {
		table[i] = new int[m]();
	}

	for (int col = m-1; col >= 0; col--) {
		for (int row = 0; row < n; ++row) {
			int rightUp = (row == 0 or col == m-1) ? 0 : table[row-1][col+1];
			int right = (col == m-1) ? 0 : table[row][col+1];
			int rightDown = (row == n-1 or col == m-1) ? 0 : table[row+1][col+1];

			table[row][col] = gold[row][col] + max(rightUp,
												max(right,
													rightDown));
		}
	}

	int optimum = INT_MIN;
	for (int i = 0; i < n; ++i) {
		optimum = max(optimum, table[i][0]);
	}

	return optimum;
}

int main(int argc, char const *argv[]) {
	int n,m;
	cin >> n >> m;
	int **gold = new int*[n]();
	for (int i = 0; i < n; ++i) {
		gold[i] = new int[m]();
		for (int j = 0; j < m; ++j) {
			cin >> gold[i][j];
		}
	}
	cout << maxGold(gold, n, m);
	return 0;
}