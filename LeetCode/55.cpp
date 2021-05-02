/**
 *    author:	vulkan
 *    created:	25.04.2020 12:35:05 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool canJump(vector<int> &nums) {
	int n = nums.size();
	if (n == 0) {
		return false;
	}

	int max_reach = nums[0];
	for (int i = 1; i <= n - 1; ++i) {
		if (i > max_reach) {
			return false;
		}

		max_reach = max(max_reach, i + nums[i]);
	}

	return true;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	cout << canJump(nums);

	return 0;
}