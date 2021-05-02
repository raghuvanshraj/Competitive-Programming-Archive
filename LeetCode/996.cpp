/**
 *    author:	vulkan
 *    created:	25.05.2020 10:50:23 AM
**/
#include <bits/stdc++.h>

using namespace std;

bool is_square(int x) {
	int l = 0, r = sqrt(x) + 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (mid * mid < x) {
			l = mid + 1;
		} else if (mid * mid > x) {
			r = mid - 1;
		} else {
			return true;
		}
	}

	return false;
}

int _numSquarefulPerms(vector<int> &arr, int idx) {
	int n = arr.size();
	if (idx == n - 1) {
		return 1;
	}

	int ans = 0;
	set<int> s;
	for (int j = idx + 1; j <= n - 1; ++j) {
		if (not s.count(arr[j])) {
			int x = arr[idx] + arr[j];
			if (is_square(x)) {
				swap(arr[idx + 1], arr[j]);
				ans += _numSquarefulPerms(arr, idx + 1);
				swap(arr[idx + 1], arr[j]);
			}

			s.insert(arr[j]);
		}
	}

	return ans;
}

int numSquarefulPerms(vector<int> &arr) {
	int n = arr.size();
	int ans = 0;
	set<int> s;
	for (int i = 0; i <= n - 1; ++i) {
		if (not s.count(arr[i])) {
			swap(arr[i], arr[0]);
			ans += _numSquarefulPerms(arr, 0);
			swap(arr[i], arr[0]);

			s.insert(arr[i]);
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

	cout << numSquarefulPerms(arr);

	return 0;
}