/**
 *    author:	vulkan
 *    created:	27.05.2020 08:50:23 PM
**/
#include <bits/stdc++.h>

using namespace std;

int maximalSquare(vector<vector<char>> &matrix) {

}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;

	vector<vector<char>> matrix(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> matrix[i][j];
		}
	}

	cout << maximalSquare(matrix);

	return 0;
}