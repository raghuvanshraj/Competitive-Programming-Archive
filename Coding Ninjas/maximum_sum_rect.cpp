/**
 *    author:	vulkan
 *    created:	28.08.2019 05:22:33 PM
**/
#include <bits/stdc++.h>

using namespace std;

int kadane(int *arr, int n) {
	int max_sum = INT_MIN, curr_sum = 0;
	for (int i = 0; i < n; ++i) {
		curr_sum += arr[i];
		max_sum = max(max_sum, curr_sum);
		if (curr_sum < 0) {
			curr_sum = 0;
		}
	}

	return max_sum;
}

int max_sum_rect(int **rect, int n, int m) {
	int max_sum = INT_MIN;
	for (int i = 0; i < m; ++i) {
		int *sum = new int[n]();
		for (int j = i; j < m; ++j) {
			for (int k = 0; k < n; ++k) {
				sum[k] += rect[k][j];
			}

			max_sum = max(kadane(sum, n), max_sum);
		}

		delete[] sum;
	}

	return max_sum;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int **rect = new int*[n]();
	for (int i = 0; i < n; ++i) {
		rect[i] = new int[m]();
		for (int j = 0; j < m; ++j) {
			cin >> rect[i][j];
		}
	}

	cout << max_sum_rect(rect, n, m);

	return 0;
}