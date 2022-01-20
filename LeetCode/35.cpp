/**
 *    author:	vulkan
 *    created:	15.01.2022 04:37:44 PM
**/
#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int> &arr, int x) {
	int n = arr.size();
	int l = 0, r = n - 1;
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (arr[mid] < x) {
			l = mid + 1;
		} else if (arr[mid] > x) {
			r = mid - 1;
		} else {
			return mid;
		}

		if (mid + 1 <= n - 1 and arr[mid] < x and arr[mid + 1] > x) {
			return mid + 1;
		}
	}

	return (x < arr[0]) ? 0 : n;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}
	int x;
	cin >> x;

	cout << searchInsert(arr, x);

	return 0;
}