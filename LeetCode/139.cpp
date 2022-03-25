/**
 *    author:	vulkan
 *    created:	05.03.2020 02:37:31 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool wordBreak(string s, vector<string>& dict) {
	unordered_set<string> dict_set;
	int m = dict.size();
	for (int i = 0; i < m; ++i) {
		dict_set.insert(dict[i]);
	}

	int n = s.size();
	vector<bool> dp(n + 1);
	dp[0] = true;
	for (int i = 1; i <= n; ++i) {
		string curr = s.substr(i - 1, 1);
		for (int j = 1; j <= i; ++j) {
			curr = curr + s.substr(j - 1, 1);
			if (dict_set.find(curr) != dict_set.end()) {
				dp[j] = dp[j] or dp[i - 1];
			}
		}
	}

	return dp[n];
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	int m;
	cin >> m;
	vector<string> dict(m);
	for (int i = 0; i < m; ++i) {
		cin >> dict[i];
	}

	cout << wordBreak(s, dict);

	return 0;
}