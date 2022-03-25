/**
 *    author:	vulkan
 *    created:	27.02.2022 09:45:07 AM
**/
#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

LL minimumRemoval(vector<int> &arr) {
	int n = arr.size();
	sort(arr.begin(), arr.end());
	pair<LL, int> dp[n + 1][2];
	dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = {0, 0};
	for (int i = 1; i <= n; ++i) {

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

	cout << minimumRemoval(arr);

	return 0;
}