/**
 *    author:	vulkan
 *    created:	15.01.2022 01:20:55 PM
**/
#include <bits/stdc++.h>

using namespace std;

int find_first(vector<int> &arr, int x) {
	int n = arr.size();
	int i = 0, j = n - 1;
	int ans = -1;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (arr[mid] < x) {
			i = mid + 1;
		} else {
			if (arr[mid] == x) {
				ans = mid;
			}
			j = mid - 1;
		}
	}

	return ans;
}

int find_last(vector<int> &arr, int x) {
	int n = arr.size();
	int i = 0, j = n - 1;
	int ans = -1;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (arr[mid] > x) {
			j = mid - 1;
		} else {
			if (arr[mid] == x) {
				ans = mid;
			}
			i = mid + 1;
		}
	}

	return ans;
}

vector<int> searchRange(vector<int> &arr, int x) {
	int s = find_first(arr, x);
	int e = find_last(arr, x);

	return vector<int>({s, e});
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}
	int x;
	cin >> x;

	vector<int> ans = searchRange(arr, x);
	cout << ans[0] << ' ' << ans[1];

	return 0;
}