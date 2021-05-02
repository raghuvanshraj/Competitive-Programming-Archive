/**
 *    author:	vulkan
 *    created:	05.03.2020 02:41:45 PM
**/
#include <bits/stdc++.h>

using namespace std;

void _wordBreak(string s, int pos, unordered_set<string> &dict_set, pair<bool, vector<string>> *dp) {
	if (s == "") {
		return;
	}

	if (dp[pos].first) {
		return;
	}

	int n = s.size();
	if (pos == n) {
		dp[pos].first = true;
		dp[pos].second.push_back("");
		return;
	}

	for (int i = pos; i < n; ++i) {
		string curr_substring = s.substr(pos, i - pos + 1);
		if (dict_set.find(curr_substring) != dict_set.end()) {
			_wordBreak(s, i + 1, dict_set, dp);
			vector<string> curr_vector = dp[i + 1].second;
			int m = curr_vector.size();
			for (int j = 0; j < m; ++j) {
				if (curr_vector[j] == "") {
					dp[pos].second.push_back(curr_substring);
				} else {
					dp[pos].second.push_back(curr_substring + " " + curr_vector[j]);
				}
			}
		}
	}

	dp[pos].first = true;
}

vector<string> wordBreak(string s, vector<string>& dict) {
	unordered_set<string> dict_set;
	int m = dict.size();
	for (int i = 0; i < m; ++i) {
		dict_set.insert(dict[i]);
	}

	int n = s.size();
	pair<bool, vector<string>> *dp = new pair<bool, vector<string>>[n + 1]();
	for (int i = 0; i < n + 1; ++i) {
		dp[i].first = false;
	}

	_wordBreak(s, 0, dict_set, dp);

	return dp[0].second;
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

	vector<string> ans = wordBreak(s, dict);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}

	return 0;
}