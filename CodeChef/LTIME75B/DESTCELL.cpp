/**
 *    author:	vulkan
 *    created:	31.08.2019 09:06:10 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int **mat = new int*[n]();
		for (int j = 0; j < n; ++j) {
			mat[j] = new int[m]();
		}

		for (int i = 0; i < n * m; ++i) {
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					mat[j][k] = 0;
				}
			}

			int counter = 0;
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					if (counter % (i + 1) == 0) {
						mat[j][k] = 1;
					}

					counter++;
				}
			}

			counter = 0;
			for (int j = 0; j < m; ++j) {
				for (int k = 0; k < n; ++k) {
					if (counter % (i + 1) == 0) {
						mat[k][j] = 1;
					}

					counter++;
				}
			}

			int ans = 0;
			for (int j = 0; j < n; ++j) {
				for (int k = 0; k < m; ++k) {
					ans += mat[j][k];
				}
			}

			// for (int j = 0; j < n; ++j) {
			// 	delete [] mat[i];
			// }

			cout << ans << ' ';
		}

		cout << endl;
	}

	return 0;
}