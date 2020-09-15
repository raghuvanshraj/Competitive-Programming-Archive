/**
 *    author:	vulkan
 *    created:	09.01.2020 01:30:56 PM
**/
#include <bits/stdc++.h>

using namespace std;

double _findMedianSortedArrays(const vector<int> &small, const vector<int> &large) {
	int n = small.size(), m = large.size();
	bool is_odd = (m + n) % 2;

	int l = 0, r = n;
	while (l <= r) {
		int mid_small = (l + r) / 2;
		int mid_large = ((n + m + 1) / 2) - mid_small;

		int a = (mid_small > 0) ? small[mid_small - 1] : INT_MIN;
		int b = (mid_large > 0) ? large[mid_large - 1] : INT_MIN;
		int x = (mid_large < m) ? large[mid_large] : INT_MAX;
		int y = (mid_small < n) ? small[mid_small] : INT_MAX;

		if (a <= x and b <= y) {
			if (is_odd) {
				return max(a, b);
			} else {
				return (double)(max(a, b) + min(x, y)) / 2;
			}
		} else {
			if (a > x) {
				r = mid_small - 1;
			} else if (b > y) {
				l = mid_small + 1;
			}
		}
	}
}

double findMedianSortedArrays(const vector<int> &a, const vector<int> &b) {
	int n = a.size(), m = b.size();
	if (n <= m) {
		return _findMedianSortedArrays(a, b);
	} else {
		return _findMedianSortedArrays(b, a);
	}
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	cout << findMedianSortedArrays(a, b);

	return 0;
}