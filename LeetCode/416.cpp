/**
 *    author:	vulkan
 *    created:	13.01.2022 11:08:52 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool canPartition(vector<int> &arr) {
	int sum = accumulate(arr.begin(), arr.end(), 0);
	if (sum & 1) {
		return false;
	}

	sum /= 2;
	int n = arr.size();
	vector<int> dp(sum + 1);
	dp[0] = true;

	for (int i = 1; i <= n; ++i) {
		for (int j = sum; j >= arr[i - 1]; --j) {
			dp[j] = dp[j] or dp[j - arr[i - 1]];
		}
	}

	return dp[sum];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << canPartition(arr);

	return 0;
}