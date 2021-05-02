/**
 *    author:	vulkan
 *    created:	27.05.2020 11:25:32 AM
**/
#include <bits/stdc++.h>

using namespace std;

int mincostTickets(vector<int> &days, vector<int> &costs) {
	int x = *max_element(days.begin(), days.end());
	vector<int> dp(x + 1, INT_MAX);
	vector<bool> travel(x + 1);
	int n = days.size();
	for (int i = 0; i <= n - 1; ++i) {
		travel[days[i]] = true;
	}

	dp[0] = 0;
	for (int i = 1; i <= x; ++i) {
		if (travel[i]) {
			dp[i] = dp[i - 1] + costs[0];
			for (int j = max(0, i - 7); j <= i - 1; ++j) {
				dp[i] = min(dp[i], dp[j] + costs[1]);
			}
			for (int j = max(0, i - 30); j <= i - 1; ++j) {
				dp[i] = min(dp[i], dp[j] + costs[2]);
			}
		} else {
			dp[i] = dp[i - 1];
		}
	}

	return dp[x];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> days(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> days[i];
	}
	vector<int> costs(3);
	for (int i = 0; i <= 2; ++i) {
		cin >> costs[i];
	}

	cout << mincostTickets(days, costs);

	return 0;
}