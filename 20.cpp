/**
 *    author:	vulkan
 *    created:	15.01.2022 04:33:05 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool isValid(string s) {
	map<char, char> mp;
	mp[')'] = '(';
	mp['}'] = '{';
	mp[']'] = '[';

	stack<char> st;
	int n = s.size();
	for (int i = 0; i <= n - 1; ++i) {
		if (mp.count(s[i])) {
			if (not st.empty() and st.top() == mp[s[i]]) {
				st.pop();
			} else {
				return false;
			}
		} else {
			st.push(s[i]);
		}
	}

	return st.empty();
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	cout << isValid(s);

	return 0;
}