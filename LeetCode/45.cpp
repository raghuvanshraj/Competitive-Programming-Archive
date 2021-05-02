/**
 *    author:	vulkan
 *    created:	18.03.2020 11:49:08 AM
**/
#include <bits/stdc++.h>

using namespace std;

int jump(vector<int> &nums) {
	int n = nums.size();
	if (n == 0) {
		return -1;
	} else if (n == 1) {
		return 0;
	}

	int max_reach = nums[0];
	int curr_steps = nums[0];
	int jumps = 1;
	for (int i = 1; i < n; ++i) {
		if (i == n - 1) {
			return jumps;
		}

		max_reach = max(max_reach, i + nums[i]);
		curr_steps--;

		if (curr_steps == 0) {
			jumps++;

			if (i >= max_reach) {
				return -1;
			}

			curr_steps = max_reach - i;
		}
	}

	return -1;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		cin >> nums[i];
	}

	cout << jump(nums);

	return 0;
}