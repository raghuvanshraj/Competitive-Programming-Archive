/**
 *    author:	vulkan
 *    created:	01.04.2020 12:47:54 PM
**/
#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int> &arr) {
	int n = arr.size();
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans ^= arr[i];
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << singleNumber(arr);

	return 0;
}