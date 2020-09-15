/**
 *    author:	vulkan
 *    created:	27.08.2019 11:31:04 AM
**/
#include <bits/stdc++.h>

using namespace std;

long max_sum(int arr[], int n) {
	long curr_sum_square = 0, curr_sum = 0, max_sum = INT_MIN;
	for (int i = 0; i < n; ++i) {
		curr_sum_square += arr[i];
		curr_sum_square = max({
			curr_sum_square,
			curr_sum + (long)pow(arr[i], 2)
		});

		curr_sum += arr[i];
		if (curr_sum < 0) {
			curr_sum = 0;
		}

		max_sum = max({
			max_sum,
			curr_sum_square
		});
	}

	return max_sum;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[n] = {0};
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << max_sum(arr, n);

	return 0;
}