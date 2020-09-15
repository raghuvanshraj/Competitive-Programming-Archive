/**
 *    author:	vulkan
 *    created:	09.01.2020 03:29:59 PM
**/
#include <bits/stdc++.h>

using namespace std;

int segregate(vector<int> &arr) {
	int n = arr.size();
	int size = n;

	for (int i = 0; i < size; ++i) {
		if (arr[i] <= 0) {
			swap(arr[--size], arr[i--]);
		}
	}

	return size;
}

int firstMissingPositive(vector<int> &arr) {
	int size = segregate(arr);
	for (int i = 0; i < size; ++i) {
		if (abs(arr[i]) - 1 < size and arr[abs(arr[i]) - 1] > 0) {
			arr[abs(arr[i]) - 1] *= -1;
		}
	}

	for (int i = 0; i < size; ++i) {
		if (arr[i] > 0) {
			return i + 1;
		}
	}

	return size + 1;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << firstMissingPositive(arr);

	return 0;
}