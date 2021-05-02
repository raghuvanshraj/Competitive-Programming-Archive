/**
 *    author:	vulkan
 *    created:	22.05.2020 10:25:15 AM
**/
#include <bits/stdc++.h>

using namespace std;

int maxValueAfterReverse(vector<int> &nums) {
	int n = nums.size();
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return nums[0];
	} else if (n == 2) {
		return abs(nums[0] - nums[1]);
	}

	int ans = 0;
	for (int i = 0; i <= n - 2; ++i) {
		ans += abs(nums[i] - nums[i + 1]);
	}

	int inc = 0;
	int min_elt = INT_MAX, max_elt = INT_MIN;
	for (int i = 0; i <= n - 2; ++i) {
		int a = nums[i], b = nums[i + 1];
		inc = max(inc, abs(nums[0] - b) - abs(a - b));
		inc = max(inc, abs(nums[n - 1] - a) - abs(a - b));
		min_elt = min(min_elt, max(a, b));
		max_elt = max(max_elt, min(a, b));
	}

	ans += max(inc, (max_elt - min_elt) * 2);

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> nums[i];
	}

	cout << maxValueAfterReverse(nums);

	return 0;
}