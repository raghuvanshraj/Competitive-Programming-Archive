/**
 *    author:	vulkan
 *    created:	12.10.2019 05:25:24 PM
**/
#include <bits/stdc++.h>

using namespace std;

void apply_transform_2(long *arr, long trans, long n) {
	for (long i = 0; i < trans; ++i) {
		long a = arr[i % n], b = arr[n - (i % n) - 1];
		arr[i % n] = a ^ b;
	}
}

void apply_transform_1(long *arr, long trans, long n) {
	while (trans--) {
		apply_transform_2(arr, n, n);
	}
}

void transform_arr(long *arr, long n, long k) {
	if (k > n / 2 and n % 2 != 0) {
		arr[n / 2] = 0;
	}

	long trans_1 = ((k / n) % 3), trans_2 = (k % n);
	apply_transform_1(arr, trans_1, n);
	apply_transform_2(arr, trans_2, n);
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		long n, k;
		cin >> n >> k;
		long arr[n];
		for (long i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		transform_arr(arr, n, k);
		for (long i = 0; i < n; ++i) {
			cout << arr[i] << ' ';
		}

		cout << endl;
	}

	return 0;
}