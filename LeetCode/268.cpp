/**
 *    author:	vulkan
 *    created:	21.01.2022 09:27:41 PM
**/
#include <bits/stdc++.h>

using namespace std;

int missingNumber(vector<int> &arr) {
	int n = arr.size();
	int total_xor = 0;
	for (int i = 0; i <= n; ++i) {
		total_xor ^= i;
	}

	int arr_xor = 0;
	for (int i = 0; i <= n - 1; ++i) {
		arr_xor ^= arr[i];
	}

	return total_xor ^ arr_xor;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << missingNumber(arr);

	return 0;
}