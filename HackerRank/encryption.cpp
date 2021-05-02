/**
 *    author:	vulkan
 *    created:	04.09.2019 02:18:43 AM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string final_string;
	while (cin) {
		string s;
		cin >> s;
		final_string = final_string + s;
	}

	int n = final_string.size();
	int rows = sqrt(n);
	int cols = (rows * rows == n) ? rows : rows + 1;
	if (rows * cols < n) {
		rows++;
	}

	string mat[rows][cols];
	int counter = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			mat[i][j] = final_string.substr(counter++, 1);
			if (counter == n) {
				break;
			}
		}
	}

	string code = "";
	for (int i = 0; i < cols; ++i) {
		for (int j = 0; j < rows; ++j) {
			code = code + mat[j][i];
		}

		code = code + " ";
	}

	cout << code;

	return 0;
}