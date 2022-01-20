/**
 *    author:	vulkan
 *    created:	19.01.2022 09:49:50 PM
**/
#include <bits/stdc++.h>

using namespace std;

int trap(vector<int> &arr) {
	int n = arr.size();
	vector<int> pre(n), suff(n);

	pre[0] = arr[0];
	for (int i = 1; i <= n - 1; ++i) {
		pre[i] = max(pre[i - 1], arr[i]);
	}

	suff[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		suff[i] = max(suff[i + 1], arr[i]);
	}

	int ans = 0;
	for (int i = 0; i <= n - 1; ++i) {
		ans += min(pre[i], suff[i]) - arr[i];
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

	cout << trap(arr);

	return 0;
}