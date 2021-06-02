/**
 *    author:	vulkan
 *    created:	02.09.2019 01:10:50 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	int min_ans = INT_MAX;
	for (int i = 0; i < n - k + 1; ++i) {
		min_ans = min(min_ans, arr[i + k - 1] - arr[i]);
	}

	cout << min_ans;

	return 0;
}