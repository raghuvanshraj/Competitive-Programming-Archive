/**
 *    author:	vulkan
 *    created:	02.04.2020 12:38:48 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool _isHappy(int n, map<int, bool> &dp, set<int> &visited) {
	if (n == 1) {
		return true;
	} else if (visited.count(n)) {
		return false;
	}

	if (dp.count(n)) {
		return dp[n];
	}

	int ans = 0;
	int temp = n;
	while (temp) {
		int curr = temp % 10;
		ans += curr * curr;
		temp /= 10;
	}

	visited.insert(n);
	dp[n] = _isHappy(ans, dp, visited);

	return dp[n];
}

bool isHappy(int n) {
	map<int, bool> dp;
	set<int> visited;

	return _isHappy(n, dp, visited);
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;

	cout << isHappy(n);

	return 0;
}