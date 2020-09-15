#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> s, int r) {
	vector<vector<int>> dp(r+1);
	for (int i = 0; i < r+1; ++i) {
		if (i == 0) {
			dp[i] = vector<int>(0);
		} else {
			
		}
	}
}

int main(int argc, char const *argv[]) {
	int r;
	vector<int> s;
	vector<int> friends = solve(s, r);
	for (int i = 0; i < friends.size(); ++i) {
		cout << friends[i] << ' ';
	}
	return 0;
}