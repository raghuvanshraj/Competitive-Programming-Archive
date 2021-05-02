/**
 *    author:	vulkan
 *    created:	23.05.2020 09:28:58 PM
**/
#include <bits/stdc++.h>

using namespace std;

int fact(int n) {
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		ans *= i;
	}

	return ans;
}

string getPermutation(int n, int k) {
	k--;
	vector<char> nums(n);
	for (int i = 0; i <= n - 1; ++i) {
		nums[i] = '1' + i;
	}

	string ans(n, ' ');
	int curr = n - 1;
	int fact_curr = fact(n - 1);
	for (int i = 0; i <= n - 1; ++i) {
		int idx = k / fact_curr;
		ans[i] = nums[idx];
		k %= fact_curr;
		if (curr > 0) {
			fact_curr /= curr;
			curr--;
		}
		nums.erase(nums.begin() + idx);
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n, k;
	cin >> n >> k;

	cout << getPermutation(n, k);

	return 0;
}