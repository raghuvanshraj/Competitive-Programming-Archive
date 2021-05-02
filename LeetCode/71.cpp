/**
 *    author:	vulkan
 *    created:	18.06.2020 06:25:57 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string s, char c = ' ') {
	vector<string> ans;
	int start_idx = 0;
	int n = s.size();
	for (int i = 0; i <= n - 1; ++i) {
		if (s[i] == c) {
			ans.push_back(s.substr(start_idx, i - start_idx));
			start_idx = i + 1;
		}
	}

	if (start_idx < n) {
		ans.push_back(s.substr(start_idx));
	}

	return ans;
}

string simplifyPath(string s) {
	vector<string> split = split_string(s, '/');
	stack<string> st;
	for (string x : split) {
		if (not x.empty()) {
			if (x == "..") {
				if (not st.empty()) {
					st.pop();
				}
			} else if (x != ".") {
				st.push(x);
			}
		}
	}

	vector<string> ans;
	while (not st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}

	reverse(ans.begin(), ans.end());
	int sz = ans.size();
	string ans_s = "/";
	for (int i = 0; i <= sz - 1; ++i) {
		ans_s = ans_s + ans[i];
		if (i < sz - 1) {
			ans_s = ans_s + "/";
		}
	}

	return ans_s;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	cout << simplifyPath(s);

	return 0;
}