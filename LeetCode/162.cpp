/**
 *    author:	vulkan
 *    created:	30.01.2022 01:33:36 PM
**/
#include <bits/stdc++.h>

using namespace std;

int findPeakElement(vector<int> &arr) {
	int n = arr.size();
	int i = 0;
	int j = n - 1;
	while (i <= j) {
		int mid = (i + j) / 2;
		int x = (mid > 0) ? arr[mid - 1] : INT_MIN;
		int y = arr[mid];
		int z = (mid < n - 1) ? arr[mid + 1] : INT_MIN;
		if (x <= y and z <= y) {
			return  mid;
		} else {
			if (x > y) {
				j = mid - 1;
			} else if (z > y) {
				i = mid + 1;
			}
		}
	}

	return -1;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << findPeakElement(arr);

	return 0;
}