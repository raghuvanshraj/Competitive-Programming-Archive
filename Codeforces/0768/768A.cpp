/**
 *    author:	vulkan
 *    created:	30.08.2019 02:41:10 PM
**/
#include <bits/stdc++.h>

using namespace std;

int n_stewards(int *arr, int n) {
	sort(arr, arr + n);
	int count = 0;
	int min_elt = *min_element(arr, arr + n);
	int max_elt = *max_element(arr, arr + n);
	for (int i = 0; i < n; ++i) {
		if (arr[i] != min_elt and arr[i] != max_elt) {
			count++;
		}
	}

	return count;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int *arr = new int[n]();
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << n_stewards(arr, n);

	return 0;
}