/**
 *    author:	vulkan
 *    created:	11.06.2020 07:21:52 PM
**/
#include <bits/stdc++.h>

using namespace std;

int islandPerimeter(vector<vector<int>> &grid) {
	int n = grid.size();
	if (n == 0) {
		return 0;
	}

	int m = grid[0].size();
	if (m == 0) {
		return 0;
	}

	int ans = 0;
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= m - 1; ++j) {
			if (grid[i][j]) {
				if (i > 0) {
					if (grid[i - 1][j] == 0) {
						ans++;
					}
				} else {
					ans++;
				}

				if (i < n - 1) {
					if (grid[i + 1][j] == 0) {
						ans++;
					}
				} else {
					ans++;
				}

				if (j > 0) {
					if (grid[i][j - 1] == 0) {
						ans++;
					}
				} else {
					ans++;
				}

				if (j < m - 1) {
					if (grid[i][j + 1] == 0) {
						ans++;
					}
				} else {
					ans++;
				}
			}
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m));
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= m - 1; ++j) {
			cin >> grid[i][j];
		}
	}

	cout << islandPerimeter(grid);

	return 0;
}