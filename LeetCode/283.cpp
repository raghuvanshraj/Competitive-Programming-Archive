/**
 *    author:	vulkan
 *    created:	04.04.2020 03:55:40 PM
**/
#include <bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int> &arr) {
	int n = arr.size();
	int j = -1;
	for (int i = 0; i < n; ++i) {
		if (arr[i] != 0) {
			swap(arr[i], arr[++j]);
		}
	}
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	moveZeroes(arr);

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << ' ';
	}

	return 0;
}