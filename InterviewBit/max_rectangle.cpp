#include <bits/stdc++.h>

using namespace std;

int max_histogram_area(vector<int> row) {
	int m = row.size();
	stack<int> st;
	int max_area = 0, area = 0;
	int i = 0;
	while (i < m) {
		if (st.empty() or row[i] >= row[st.top()]) {
			st.push(i++);
		} else {
			int t = st.top();
			st.pop();
			area = row[t] * i;

			if (not st.empty()) {
				area = row[t] * (i - st.top() - 1);
			}

			max_area = max(max_area, area);
		}
	}

	while (not st.empty()) {
		int t = st.top();
		st.pop();
		area = row[t] * i;

		if (not st.empty()) {
			area = row[t] * (i - st.top() - 1);
		}

		max_area = max(max_area, area);
	}

	return max_area;
}

int maximalRectangle(vector<vector<int>> &matrix) {
	int n = matrix.size(), m = matrix[0].size();

	int max_result = max_histogram_area(matrix[0]);
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (matrix[i][j]) {
				matrix[i][j] += matrix[i-1][j];
			}
		}

		int curr_result = max_histogram_area(matrix[i]);
		max_result = max(max_result, curr_result);
	}

	return max_result;
}

int main(int argc, char const *argv[]) {
	int n,m;
	cin >> n >> m;
	vector<vector<int>> matrix(n);
	for (int i = 0; i < n; ++i) {
		matrix[i] = vector<int>(n);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> matrix[i][j];
		}
	}

	cout << maximalRectangle(matrix);
	
	return 0;
}