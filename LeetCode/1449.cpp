/**
 *    author:	vulkan
 *    created:	16.05.2020 10:50:56 PM
**/
#include <bits/stdc++.h>

using namespace std;

string largestNumber(vector<int> &cost, int target) {
	vector<pair<int, int>> dp(target + 1, {0, 0});
	for (int i = 1; i <= target; ++i) {
		for (int j = 1; j <= 9; ++j) {
			if (i >= cost[j - 1]) {
				if (i - cost[j - 1] > 0 and dp[i - cost[j - 1]].first == 0) {
					continue;
				}

				if (dp[i - cost[j - 1]].first + 1 >= dp[i].first) {
					dp[i] = {dp[i - cost[j - 1]].first + 1, j};
				}
			}
		}
	}

	int n = dp[target].first;
	string ans(n, ' ');
	int i = 0;
	int curr_val = target;
	while (curr_val) {
		int num = dp[curr_val].second;
		if (num == 0) {
			return "0";
		}
		ans[i++] = '0' + num;
		curr_val -= cost[num - 1];
	}

	sort(ans.begin(), ans.end(), greater<char>());

	return ans;
}

int main(int argc, char const *argv[]) {
	vector<int> cost(9);
	for (int i = 0; i <= 8; ++i) {
		cin >> cost[i];
	}
	int target;
	cin >> target;

	cout << largestNumber(cost, target);

	return 0;
}