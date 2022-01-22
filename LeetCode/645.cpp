/**
 *    author:	vulkan
 *    created:	21.01.2022 09:31:29 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> findErrorNums(vector<int> &arr) {
	int n = arr.size();
	int total_xor = 0;
	int arr_xor = 0;
	vector<int> ans(2);
	for (int i = 0; i <= n - 1; ++i) {
		total_xor ^= (i + 1);
		arr_xor ^= abs(arr[i]);
		int x = abs(arr[i]) - 1;
		if (arr[x] < 0) {
			ans[0] = abs(arr[i]);
		} else {
			arr[x] *= -1;
		}
	}
	total_xor ^= ans[0];
	ans[1] = arr_xor ^ total_xor;

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	vector<int> ans = findErrorNums(arr);
	for (int x : ans) {
		cout << x << ' ';
	}

	return 0;
}