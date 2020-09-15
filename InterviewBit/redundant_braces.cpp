#include <bits/stdc++.h>

using namespace std;

int braces(string s) {
	stack<int> st;
	int n = s.size();

	for (int i = 0; i < n-2; ++i) {
		if (s[i] == '(' and s[i+2] == ')') {
			return 1;
		}
	}

	for (int i = 0; i < n-1; ++i) {
		if (s[i] == '(') {
			st.push(i);
		} else if (s[i] == ')') {
			if (st.empty()) {
				return 1;
			}

			int prev_idx = st.top(), curr_idx;
			st.pop();
			if (s[i+1] == ')') {
				if (st.empty()) {
					return 1;
				}

				curr_idx = st.top();
			}

			if (prev_idx - curr_idx == 1) {
				return 1;
			}
		}
	}

	if (s[n-1] == ')') {
		st.pop();
	}

	if (not st.empty()) {
		return 1;
	}

	return 0;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	cout << braces(s);
	
	return 0;
}