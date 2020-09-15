#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &matrix) {
	if (matrix.empty()) {
		return 0;
	}

	int n = matrix.size();
	int m = matrix[0].size();
	vector<vector<int>> prefix_matrix(n);
	for (int i = 0; i < n; ++i) {
		prefix_matrix[i] = vector<int>(m);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == 0 and j == 0) {
				prefix_matrix[i][j] = matrix[i][j];
			} else if (i == 0) {
				prefix_matrix[i][j] = prefix_matrix[i][j-1] + matrix[i][j];
			} else if (j == 0) {
				prefix_matrix[i][j] = prefix_matrix[i-1][j] + matrix[i][j];
			} else {
				prefix_matrix[i][j] = prefix_matrix[i][j-1] 
									+ prefix_matrix[i-1][j] 
									- prefix_matrix[i-1][j-1]
									+ matrix[i][j];
			}
		}
	}

	int count = 0;
	for (int x2 = 0; x2 < n; ++x2) {
		for (int y2 = 0; y2 < m; ++y2) {
			for (int x1 = 0; x1 < x2+1; ++x1) {
				for (int y1 = 0; y1 < y2+1; ++y1) {
					int curr_sum;
					if (x1 == 0 and y1 == 0) {
						curr_sum = prefix_matrix[x2][y2];
					} else if (x1 == 0) {
						curr_sum = prefix_matrix[x2][y2] - prefix_matrix[x2][y1-1];
					} else if (y1 == 0) {
						curr_sum = prefix_matrix[x2][y2] - prefix_matrix[x1-1][y2];
					} else {
						curr_sum = prefix_matrix[x2][y2]
									+ prefix_matrix[x1-1][y1-1]
									- prefix_matrix[x1-1][y2]
									- prefix_matrix[x2][y1-1];
					}

					if (curr_sum == 0) {
						count++;
					}
				}
			}
		}
	}

	return count;
}

int main(int argc, char const *argv[]) {
	int n,m;
	cin >> n >> m;
	vector<vector<int>> matrix(n);
	for (int i = 0; i < n; ++i) {
		matrix[i] = vector<int>(m);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> matrix[i][j];
		}
	}

	cout << solve(matrix);
	
	return 0;
}