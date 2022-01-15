/**
 *    author:	vulkan
 *    created:	15.01.2022 12:26:25 PM
**/
#include <bits/stdc++.h>

using namespace std;

map<int, string> keys;
vector<string> ans;

void populate_keys() {
	string curr = "abc";
	for (int i = 2; i <= 6; ++i) {
		keys[i] = curr;
		curr[0] += 3;
		curr[1] += 3;
		curr[2] += 3;
	}
	keys[7] = "pqrs";
	keys[8] = "tuv";
	keys[9] = "wxyz";
}

void _letterCombinations(string s, int idx, string curr) {
	if (idx == s.size()) {
		if (curr != "") {
			ans.push_back(curr);
		}
	}

	int x = s[idx] - '0';
	string key = keys[x];
	int n = key.size();
	for (int i = 0; i <= n - 1; ++i) {
		_letterCombinations(s, idx + 1, curr + key.substr(i, 1));
	}
}

vector<string> letterCombinations(string s) {
	populate_keys();
	_letterCombinations(s, 0, "");
	return ans;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	vector<string> ans = letterCombinations(s);
	for (string x : ans) {
		cout << x << endl;
	}

	return 0;
}