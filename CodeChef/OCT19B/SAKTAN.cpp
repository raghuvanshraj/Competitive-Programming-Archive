/**
 *    author:	vulkan
 *    created:	12.10.2019 04:32:51 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m, q;
		cin >> n >> m >> q;

		int *row_count = new int[n]();
		int *col_count = new int[m]();
		while (q--) {
			int r, c;
			cin >> r >> c;
			row_count[r - 1]++;
			col_count[c - 1]++;
		}

		int row_even_count = 0;
		for (int i = 0; i < n; ++i) {
			if (row_count[i] % 2 == 0) {
				row_even_count++;
			}
		}

		long odd_cells = (long)n * m;
		for (int i = 0; i < m; ++i) {
			if (col_count[i] % 2 == 0) {
				odd_cells -= (long)row_even_count;
			} else {
				odd_cells -= (long)(n - row_even_count);
			}
		}

		cout << odd_cells << endl;

		delete [] row_count;
		delete [] col_count;
	}

	return 0;
}