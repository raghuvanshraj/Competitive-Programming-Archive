/**
 *    author:	vulkan
 *    created:	07.06.2020 12:18:28 PM
**/
#include <bits/stdc++.h>

using namespace std;

int numDecodings(string s) {
	int n = s.size();
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		arr[i] = s[i] - '0';
	}

	vector<int> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (arr[i - 1] > 0) {
			dp[i] = dp[i - 1];
		}

		if (i >= 2 and arr[i - 2] > 0) {
			int x = arr[i - 1] + arr[i - 2] * 10;
			if (x >= 1 and x <= 26) {
				dp[i] += dp[i - 2];
			}
		}
	}

	return dp[n];
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	cout << numDecodings(s);

	return 0;
}