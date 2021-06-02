/**
 *    author:	vulkan
 *    created:	03.09.2019 11:45:57 AM
**/
#include <bits/stdc++.h>

using namespace std;

pair<bool, string> _crack(string code, map<string, pair<bool, string>> &dp, unordered_set<string> &dict, string cracked) {
	if (code == "") {
		return {true, cracked};
	}

	if (dp.find(code) != dp.end()) {
		return dp[code];
	}

	int n = code.size();
	for (int i = 1; i < n + 1; ++i) {
		string curr_substring = code.substr(0, i);
		if (dict.find(curr_substring) != dict.end()) {
			string new_string;
			if (cracked == "") {
				new_string = curr_substring;
			} else {
				new_string = cracked + " " + curr_substring;
			}

			pair<bool, string> ans = _crack(code.substr(i), dp, dict, new_string);
			if (ans.first) {
				return dp[code] = ans;
			}
		}
	}

	return dp[code] = {false, ""};
}

string crack(string code, unordered_set<string> dict) {
	map<string, pair<bool, string>> dp;
	pair<bool, string> ans = _crack(code, dp, dict, "");

	if (ans.first) {
		return ans.second;
	} else {
		return "WRONG PASSWORD";
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		unordered_set<string> dict;
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			dict.insert(s);
		}

		string code;
		cin >> code;

		cout << crack(code, dict) << endl;
	}

	return 0;
}