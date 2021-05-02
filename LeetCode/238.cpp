/**
 *    author:	vulkan
 *    created:	15.04.2020 04:46:41 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> productExceptSelf(vector<int> &arr) {
	int n = arr.size();
	if (n == 1) {
		return {0};
	}

	vector<int> left(n), right(n), ans(n);

	left[0] = arr[0];
	for (int i = 1; i < n; ++i) {
		left[i] = left[i - 1] * arr[i];
	}

	right[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		right[i] = right[i + 1] * arr[i];
	}

	for (int i = 0; i < n; ++i) {
		if (i == 0) {
			ans[i] = right[i + 1];
		} else if (i == n - 1) {
			ans[i] = left[i - 1];
		} else {
			ans[i] = left[i - 1] * right[i + 1];
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	vector<int> ans = productExceptSelf(arr);
	for (int x : ans) {
		cout << x << ' ';
	}

	return 0;
}