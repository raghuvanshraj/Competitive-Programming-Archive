/**
 *    author:	vulkan
 *    created:	20.01.2022 11:19:36 PM
**/
#include <bits/stdc++.h>

using namespace std;

int ceil(int x, int y) {
	if (x % y == 0) {
		return x / y;
	}
	return x / y + 1;
}

bool is_possible(vector<int> &arr, int val, int max_ops) {
	for (int x : arr) {
		max_ops -= max(ceil(x, val) - 1, 0);
		if (max_ops < 0) {
			return false;
		}
	}

	return true;
}

int minimumSize(vector<int> &arr, int max_ops) {
	int n = arr.size();
	int l = 1;
	int r = *max_element(arr.begin(), arr.end());
	int ans = r;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (is_possible(arr, mid, max_ops)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
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
	int max_ops;
	cin >> max_ops;

	cout << minimumSize(arr, max_ops);

	return 0;
}