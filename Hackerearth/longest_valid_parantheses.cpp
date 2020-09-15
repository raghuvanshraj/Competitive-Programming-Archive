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
				res = max(res, i-st.top());
			} else {
				st.push(i);
			}
		}
	}

	return res;
}

int main(int argc, char const *argv[]) {
	string s;
	while (getline(cin, s)) {
		cout << longestValidParentheses(s) << endl;
	}
	return 0;
}