/**
 *    author:	vulkan
 *    created:	24.08.2019 12:29:46 PM
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll min_coins(ll *arr, int n) {
	ll dp[n][2] = {0};

	dp[0][0] = abs(arr[0] + 1);
	dp[0][1] = abs(arr[0] - 1);

	for (int i = 1; i < n; ++i) {
		dp[i][0] = min(dp[i - 1][1] + (ll)abs(arr[i] + 1), dp[i - 1][0] + (ll)abs(arr[i] - 1));
		dp[i][1] = min(dp[i - 1][1] + (ll)abs(arr[i] - 1), dp[i - 1][0] + (ll)abs(arr[i] + 1));
	}

	return dp[n - 1][1];
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	ll *arr = new ll[n]();
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << min_coins(arr, n);

	return 0;
}