/**
 *    author:	vulkan
 *    created:	29.05.2020 10:59:39 PM
**/
#include <bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int> &arr) {
	int n = arr.size();
	bool found = false;
	for (int i = n - 2; i >= 0; --i) {
		if (arr[i] < arr[i + 1]) {
			found = true;
			sort(arr.begin() + i + 1, arr.end());
			int j = upper_bound(arr.begin() + i + 1, arr.end(), arr[i]) - arr.begin();
			swap(arr[i], arr[j]);
			sort(arr.begin() + i + 1, arr.end());
			break;
		}
	}

	if (not found) {
		sort(arr.begin(), arr.end());
	}
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	nextPermutation(arr);

	for (int i = 0; i <= n - 1; ++i) {
		cout << arr[i] << ' ';
	}

	// vector<int> arr({3,2});
	// cout << *upper_bound(arr.begin(), arr.end(), 2, greater<int>());

	return 0;
}