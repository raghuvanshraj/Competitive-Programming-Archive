/**
 *    author:	vulkan
 *    created:	16.05.2020 10:36:44 AM
**/
#include <bits/stdc++.h>

using namespace std;

int firstMissingPositive(vector<int> &arr) {
	int n = arr.size();
	int j = 0;
	for (int i = 0; i <= n - 1; ++i) {
		if (arr[i] > 0) {
			swap(arr[i], arr[j++]);
		}
	}

	for (int i = 0; i <= j - 1; ++i) {
		if (abs(arr[i]) - 1 < j) {
			if (arr[abs(arr[i]) - 1] > 0) {
				arr[abs(arr[i]) - 1] *= -1;
			}
		}
	}

	for (int i = 0; i <= j - 1; ++i) {
		if (arr[i] > 0) {
			return i + 1;
		}
	}

	return j + 1;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << firstMissingPositive(arr);

	return 0;
}