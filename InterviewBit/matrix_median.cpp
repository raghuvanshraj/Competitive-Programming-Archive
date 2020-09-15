/**
 *    author:	vulkan
 *    created:	26.08.2019 01:23:57 PM
**/
#include <bits/stdc++.h>

using namespace std;

int findMedian(vector<vector<int>> &mat) {
	int n = mat.size(), m = mat[0].size();
	int min_mat = INT_MAX, max_mat = INT_MIN;
	for (int i = 0; i < n; ++i) {
		min_mat = min(min_mat, mat[i][0]);
		max_mat = max(max_mat, mat[i][m - 1]);
	}

	int desired_less = (n * m + 1) / 2;
	while (min_mat < max_mat) {
		int mid = (min_mat + max_mat) / 2;
		int lesser = 0;
		for (int i = 0; i < n; ++i) {
			lesser += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
		}

		if (lesser < desired_less) {
			min_mat = mid + 1;
		} else {
			max_mat = mid;
		}
	}

	return min_mat;
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

	cout << findMedian(mat);

	return 0;
}