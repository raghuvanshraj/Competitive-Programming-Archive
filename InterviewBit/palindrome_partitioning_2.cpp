#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string s) {
	int j = s.size()-1;
	int i = 0;
	while (i <= j) {
		if (s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}

	return true;
}

int _minCut(string s, int pos, int *dp) {
	if (s == "") {
		return 0;
	}

	int n = s.size();
	if (pos == n) {
		return -1;
	}

	if (dp[pos] != INT_MAX) {
		return dp[pos];
	}

	for (int i = pos; i < n; ++i) {
		string curr_substring = s.substr(pos, i-pos+1);
		if (is_palindrome(curr_substring)) {
			int curr_result = _minCut(s, i+1, dp);
			dp[pos] = min(dp[pos], curr_result + 1);
		}
	}

	return dp[pos];
}

int minCut(string s) {
	int n = s.size();
	int *dp = new int[n]();
	for (int i = 0; i < n; ++i) {
		dp[i] = INT_MAX;
	}

	return _minCut(s, 0, dp);
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	cout << minCut(s);
	
	return 0;
}