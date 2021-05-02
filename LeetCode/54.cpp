/**
 *    author:	vulkan
 *    created:	01.06.2020 04:55:50 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix) {
	int n = matrix.size();
	int m = (n > 0) ? matrix[0].size() : -1;
	if (m == -1 or m == 0) {
		return {};
	}

	vector<int> ans(n * m);
	int end_i = n / 2, end_j = m / 2;
	int u = 0, d = n - 1, l = 0, r = m - 1;
	int k = 0;
	while (k < n * m) {
		for (int i = l; i <= r; ++i) {
			ans[k++] = matrix[u][i];
		}
		u++;

		if (k == n * m) {
			break;
		}

		for (int i = u; i <= d; ++i) {
			ans[k++] = matrix[i][r];
		}
		r--;

		if (k == n * m) {
			break;
		}

		for (int i = r; i >= l; --i) {
			ans[k++] = matrix[d][i];
		}
		d--;

		if (k == n * m) {
			break;
		}

		for (int i = d; i >= u; --i) {
			ans[k++] = matrix[i][l];
		}
		l++;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(m));
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= m - 1; ++j) {
			cin >> matrix[i][j];
		}
	}

	vector<int> ans = spiralOrder(matrix);
	for (int x : ans) {
		cout << x << ' ';
	}

	return 0;
}