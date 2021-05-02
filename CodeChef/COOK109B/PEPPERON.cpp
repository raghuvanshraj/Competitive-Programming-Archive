#include <bits/stdc++.h>

using namespace std;

int min_diff(string mat[], int n) {
	int mat_int[n][n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			mat_int[i][j] = mat[i][j] - '0';
		}
	}

	int diff[n] = {0};
	for (int i = 0; i < n; ++i) {
		int left_ans = 0;
		for (int j = 0; j < n/2; ++j) {
			left_ans += mat_int[i][j];
		}

		int right_ans = 0;
		for (int j = n/2; j < n; ++j) {
			right_ans += mat_int[i][j];
		}
		
		diff[i] = left_ans - right_ans;
	}

	int original_diff = accumulate(diff, diff + n, 0);
	int min_diff = abs(original_diff);
	for (int i = 0; i < n; ++i) {
		min_diff = min(min_diff, abs(original_diff - (2 * diff[i])));
	}

	return min_diff;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string mat[n];
		for (int i = 0; i < n; ++i) {
			cin >> mat[i];
		}

		cout << min_diff(mat, n) << endl;
	}
	
	return 0;
}