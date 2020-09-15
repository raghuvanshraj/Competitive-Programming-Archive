/**
 *    author:	vulkan
 *    created:	26.08.2019 01:42:18 PM
**/
#include <bits/stdc++.h>

using namespace std;

int search(const vector<int> &arr, int elt) {
	int n = arr.size();
	int i = 0, j = n - 1;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (arr[mid] >= arr[i]) {
			if (arr[mid] > elt) {
				if (elt >= arr[i]) {
					j = mid - 1;
				} else {
					i = mid + 1;
				}
			} else if (arr[mid] < elt) {
				i = mid + 1;
			} else {
				return mid;
			}
		} else {
			if (arr[mid] > elt) {
				j = mid - 1;
			} else if (arr[mid] < elt) {
				if (elt <= arr[j]) {
					i = mid + 1;
				} else {
					j = mid - 1;
				}
			} else {
				return mid;
			}
		}
	}

	return -1;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int elt;
	cin >> elt;

	cout << search(arr, elt);

	return 0;
}