/**
 *    author:	vulkan
 *    created:	19.04.2020 01:09:43 PM
**/
#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> &arr, int l, int r, int target) {
	while (l <= r) {
		int mid = (l + r) / 2;
		if (arr[mid] < target) {
			l = mid + 1;
		} else if (arr[mid] > target) {
			r = mid - 1;
		} else {
			return mid;
		}
	}

	return -1;
}

int search(vector<int> &arr, int target) {
	int n = arr.size();
	if (n == 0) {
		return -1;
	}

	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (arr[mid] <= arr[n - 1]) {
			r = mid - 1;
		} else if (arr[mid] > arr[n - 1]) {
			l = mid + 1;
		}
	}

	int ans = binary_search(arr, l, n - 1, target);
	if (ans == -1) {
		return binary_search(arr, 0, l - 1, target);
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}
	int target;
	cin >> target;

	cout << search(arr, target);

	return 0;
}