/**
 *    author:	vulkan
 *    created:	01.10.2019 06:05:23 PM
**/
#include <bits/stdc++.h>

using namespace std;

int longestValidParentheses(string s) {
	int n = s.size();
	stack<int> st;
	st.push(-1);
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '(') {
			st.push(i);
		} else {
			st.pop();
			if (not st.empty()) {
				res = max(res, i - st.top());
			} else {
				st.push(i);
			}
		}
	}

	return res;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	cout << longestValidParentheses(s);

	return 0;
}