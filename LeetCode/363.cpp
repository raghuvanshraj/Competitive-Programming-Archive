/**
 *    author:	vulkan
 *    created:	14.03.2020 09:47:32 AM
**/
#include <bits/stdc++.h>

using namespace std;

int calc_max(vector<int> arr, int k) {
	int n = arr.size();

	set<int> sums;
	sums.insert(0);
	int curr_sum = 0, max_sum = INT_MIN;
	for (int i = 0; i < n; ++i) {
		curr_sum += arr[i];
		set<int>::iterator it = sums.lower_bound(curr_sum - k);
		if (it != sums.end()) {
			max_sum = max(max_sum, curr_sum - *it);
		}

		sums.insert(curr_sum);
	}

	return max_sum;
}

int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
	int n = matrix.size(), m;
	if (n == 0) {
		return 0;
	} else {
		m = matrix[0].size();
		if (m == 0) {
			return 0;
		}
	}

	int ans = INT_MIN;
	for (int i = 0; i < m; ++i) {
		vector<int> col_sum(n);
		for (int j = i; j < m; ++j) {
			for (int curr_row = 0; curr_row < n; ++curr_row) {
				col_sum[curr_row] += matrix[curr_row][j];
			}

			ans = max({
				ans,
				calc_max(col_sum, k)
			});
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> matrix(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> matrix[i][j];
		}
	}

	int k;
	cin >> k;

	cout << maxSumSubmatrix(matrix, k) << endl;

	return 0;
}