/**
 *    author:	vulkan
 *    created:	05.03.2020 02:37:31 PM
**/
#include <bits/stdc++.h>

using namespace std;

int _wordBreak(string &s, int pos, unordered_set<string> &dict_set, int *dp) {
	if (s == "") {
		return 0;
	}

	int n = s.size();
	if (pos == n) {
		return 1;
	}

	if (dp[pos] != -1) {
		return dp[pos];
	}

	for (int i = pos; i < n; ++i) {
		string curr_substring = s.substr(pos, i - pos + 1);
		if (dict_set.find(curr_substring) != dict_set.end()) {
			int res = _wordBreak(s, i + 1, dict_set, dp);
			if (res) {
				dp[pos] = 1;
				return 1;
			}
		}
	}

	dp[pos] = 0;
	return 0;
}

bool wordBreak(string s, vector<string>& dict) {
	unordered_set<string> dict_set;
	int m = dict.size();
	for (int i = 0; i < m; ++i) {
		dict_set.insert(dict[i]);
	}

	int n = s.size();
	int *dp = new int[n]();
	for (int i = 0; i < n; ++i) {
		dp[i] = -1;
	}

	return _wordBreak(s, 0, dict_set, dp);
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