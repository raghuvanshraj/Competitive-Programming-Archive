/**
 *    author:	vulkan
 *    created:	26.08.2019 05:22:37 PM
**/
#include <bits/stdc++.h>

using namespace std;

int searchMatrix(vector<vector<int>> &mat, int elt) {
	int n = mat.size(), m = mat[0].size();
	int i = 0, j = n * m - 1;
	while (i <= j) {
		int mid = (i + j) / 2;
		int r = mid / m, c = mid % m;
		// cout << mid << ' ';
		if (mat[r][c] < elt) {
			i = mid + 1;
		} else if (mat[r][c] > elt) {
			j = mid - 1;
		} else {
			return 1;
		}
	}

	return 0;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> mat(n);
	for (int i = 0; i < n; ++i) {
		mat[i] = vector<int>(m);
		for (int j = 0; j < m; ++j) {
			cin >> mat[i][j];
		}
	}

	int elt;
	cin >> elt;

	cout << searchMatrix(mat, elt);

	return 0;
}