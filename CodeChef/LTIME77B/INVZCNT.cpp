/**
 *    author:	vulkan
 *    created:	27.10.2019 11:04:52 AM
**/
#include <bits/stdc++.h>
#define MAX_BITS 32

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		int arr[n];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		int **binary_arr = convert_to_binary(arr, n);

		while (q--) {
			int k;
			int *k_bin = convert_num_to_binary(k);
			int *counts = new int[MAX_BITS]();
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < MAX_BITS; ++j) {
					if (binary_arr[i][j] xor k_bin[j]) {
						counts[j]++;
						break;
					}
				}
			}
		}
	}

	return 0;
}