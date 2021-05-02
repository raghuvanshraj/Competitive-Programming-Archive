/**
 *    author:	vulkan
 *    created:	22.05.2020 08:21:57 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> &nums, int x) {
	int n = nums.size();
	map<int, int> mp;
	for (int i = 0; i <= n - 1; ++i) {
		if (mp.count(x - nums[i])) {
			return {mp[x - nums[i]], i};
		} else {
			mp[nums[i]] = i;
		}
	}

	return { -1, -1};
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> nums[i];
	}
	int target;
	cin >> target;

	vector<int> ans = twoSum(nums, target);
	cout << ans[0] << ' ' << ans[1];

	return 0;
}