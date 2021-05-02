/**
 *    author:	vulkan
 *    created:	20.05.2020 08:58:45 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool is_valid(string s) {
	int bal_cnt = 0;
	for (char c : s) {
		if (c == '(') {
			bal_cnt++;
		} else if (c == ')') {
			if (bal_cnt == 0) {
				return false;
			}

			bal_cnt--;
		}
	}

	return (bal_cnt == 0);
}

vector<string> removeInvalidParentheses(string s) {
	vector<string> ans;
	queue<string> qu;
	set<string> visited;
	qu.push(s);
	visited.insert(s);
	bool found = false;
	while (not qu.empty()) {
		string curr = qu.front();
		qu.pop();
		if (is_valid(curr)) {
			ans.push_back(curr);
			found = true;
		}

		if (found) {
			continue;
		}

		for (int i = 0; i <= curr.size() - 1; ++i) {
			if (curr[i] == '(' or curr[i] == ')') {
				string next_str = curr.substr(0, i) + curr.substr(i + 1);
				if (not visited.count(next_str)) {
					qu.push(next_str);
					visited.insert(next_str);
				}
			}
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	vector<string> ans = removeInvalidParentheses(s);
	for (string s : ans) {
		cout << s << endl;
	}

	return 0;
}