#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &friends, vector<int> &capacity, vector<int> &cost) {
	int maxCapacity = *max_element(friends.begin(), friends.end());
	// cout << maxCapacity << endl;
	int **dp = new int*[maxCapacity+1]();
	int n = capacity.size();
	for (int i = 0; i < maxCapacity+1; ++i) {
		dp[i] = new int[n+1]();
		if (i == 0) {
			for (int j = 0; j < n+1; ++j) {
				dp[i][j] = 0;
			}
		} else {
			for (int j = 0; j < n+1; ++j) {
				dp[i][j] = INT_MAX;
			}
		}
	}

	for (int i = 0; i < maxCapacity+1; ++i) {
		for (int j = 1; j < n+1; ++j) {
			if (capacity[j-1] <= i) {
				if (dp[i-capacity[j-1]][j] == INT_MAX) {
					dp[i][j] = dp[i][j-1];
				} else {
					dp[i][j] = min(dp[i][j-1], dp[i-capacity[j-1]][j] + cost[j-1]);
				}
			} else {
				dp[i][j] = dp[i][j-1];
			}
		}
	}

	int finalCost = 0;
	for (int i = 0; i < friends.size(); ++i) {
		finalCost += dp[friends[i]][n];
	}

	// for (int i = 0; i < maxCapacity+1; ++i) {
	// 	for (int j = 0; j < n+1; ++j) {
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << endl;
	// }

	return finalCost;
}

int main(int argc, char const *argv[]) {
	int numFriends, numDishes;
	cin >> numFriends >> numDishes;
	vector<int> friends(numFriends), capacity(numDishes), cost(numDishes);
	for (int i = 0; i < numFriends; ++i) {
		cin >> friends[i];
	}
	for (int i = 0; i < numDishes; ++i) {
		cin >> capacity[i];
	}
	for (int i = 0; i < numDishes; ++i) {
		cin >> cost[i];
	}

	cout << solve(friends, capacity, cost);
	return 0;
}