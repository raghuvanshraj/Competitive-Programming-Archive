/**
 *    author:	vulkan
 *    created:	12.10.2019 06:10:50 PM
**/
#include <bits/stdc++.h>
#define MAX_ELT 1000001

using namespace std;

int calc_star(int arr[], int n, int *elt_idx) {
	int *star_value = new int[n]();
	for (int i = 0; i < n; ++i) {
		int curr_elt = arr[i];
		for (int j = 1; j <= sqrt(curr_elt); ++j) {
			if (curr_elt % j == 0) {
				int a = j, b = curr_elt / j;
				if (elt_idx[a] > i) {
					star_value[elt_idx[a]]++;
				}

				if (a != b and elt_idx[b] > i) {
					star_value[elt_idx[b]]++;
				}
			}
		}
	}

	return *max_element(star_value, star_value + n);
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n];
		int *elt_idx = new int[MAX_ELT]();
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			elt_idx[arr[i]] = i;
		}

		cout << calc_star(arr, n, elt_idx) << endl;
	}

	return 0;
}