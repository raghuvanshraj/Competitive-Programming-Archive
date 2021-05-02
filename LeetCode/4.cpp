/**
 *    author:	vulkan
 *    created:	07.03.2020 03:33:09 PM
**/
#include <bits/stdc++.h>

using namespace std;

double median(int left, int right, int size) {
	if (size % 2) {
		return left;
	} else {
		return double(left + right) / 2;
	}
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
	int n = nums1.size(), m = nums2.size();
	if (n == 0) {
		return (m == 1) ? nums2[0] : median(nums2[(m - 1) / 2], nums2[(m - 1) / 2 + 1], m);
	} else if (m == 0) {
		return (n == 1) ? nums1[0] : median(nums1[(n - 1) / 2], nums1[(n - 1) / 2 + 1], n);
	}

	if (n > m) {
		swap(nums1, nums2);
		swap(n, m);
	}

	int l = 0, h = n;
	while (l <= h) {
		int i = (l + h) / 2;
		int j = (n + m + 1) / 2 - i;

		if (i > 0 and j > 0) {
			int left = max(nums1[i - 1], nums2[j - 1]);
			int right = (i < n) ? min(nums1[i], nums2[j]) : nums2[j];

			if (left > right) {
				if (left == nums1[i - 1]) {
					h = i;
				} else {
					l = i + 1;
				}
			} else {
				return median(left, right, n + m);
			}
		} else if (i == 0) {
			int right = (j < m) ? min(nums1[0], nums2[j]) : nums1[0];
			if (nums2[j - 1] > right) {
				l = i + 1;
			} else {
				return median(nums2[j - 1], right, n + m);
			}
		} else if (j == 0) {
			if (nums1[i - 1] > nums2[0]) {
				h = i;
			} else {
				return median(nums1[i - 1], nums2[0], n + m);
			}
		}
	}

	return -1;
}


int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<int> nums1(n), nums2(m);

	for (int i = 0; i < n; ++i) {
		cin >> nums1[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> nums2[i];
	}

	double ans = findMedianSortedArrays(nums1, nums2);
	printf("%.1f\n", ans);

	return 0;
}