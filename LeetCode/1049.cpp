/**
 *    author:	vulkan
 *    created:	27.05.2020 07:40:44 PM
**/
#include <bits/stdc++.h>

using namespace std;

int lastStoneWeightII(vector<int> &stones) {
	int n = stones.size();
	int s = accumulate(stones.begin(), stones.end(), 0);
	vector<vector<bool>> dp(n + 1, vector<bool>(s / 2 + 1));
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = true;
	}

	int s2 = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= s / 2; ++j) {
			if (dp[i - 1][j] or (j >= stones[i - 1] and dp[i - 1][j - stones[i - 1]])) {
				dp[i][j] = true;
				s2 = j;
			}
		}
	}

	return s - 2 * s2;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> stones(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> stones[i];
	}

	cout << lastStoneWeightII(stones);

	return 0;
}