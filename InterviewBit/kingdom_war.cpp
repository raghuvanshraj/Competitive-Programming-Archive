#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &matrix) {
	int n = matrix.size(), m = matrix[0].size();
	int **suffix_matrix = new int*[n]();
	for (int i = 0; i < n; ++i) {
		suffix_matrix[i] = new int[m]();
	}

	for (int i = n-1; i >= 0; --i) {
		for (int j = m-1; j >= 0; --j) {
			if (i == n-1 and j == m-1) {
				suffix_matrix[i][j] = matrix[i][j];
			} else if (i == n-1) {
				suffix_matrix[i][j] = matrix[i][j] + suffix_matrix[i][j+1];
			} else if (j == m-1) {
				suffix_matrix[i][j] = matrix[i][j] + suffix_matrix[i+1][j];
			} else {
				suffix_matrix[i][j] = suffix_matrix[i+1][j]
								+ suffix_matrix[i][j+1]
								- suffix_matrix[i+1][j+1]
								+ matrix[i][j];
			}
		}
	}

	int max_sum = INT_MIN;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			max_sum = max(max_sum, suffix_matrix[i][j]);
		}
	}

	return max_sum;
}

int main(int argc, char const *argv[]) {
	int n,m;
	cin >> n >> m;
	vector<vector<int>> matrix(n);
	for (int i = 0; i < n; ++i) {
		matrix[i] = vector<int>(m);
		for (int j = 0; j < m; ++j) {
			cin >> matrix[i][j];
		}
	}

	cout << solve(matrix);
	
	return 0;
}