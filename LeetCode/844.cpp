/**
 *    author:	vulkan
 *    created:	09.04.2020 12:43:30 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool backspaceCompare(string s, string t) {
	int n = s.size(), m = t.size();
	int is = 0, js = 0;
	while (js < n) {
		if (s[js] == '#') {
			if (is > 0) {
				is--;
			}
		} else {
			s[is++] = s[js];
		}

		js++;
	}

	int it = 0, jt = 0;
	while (jt < m) {
		if (t[jt] == '#') {
			if (it > 0) {
				it--;
			}
		} else {
			t[it++] = t[jt];
		}

		jt++;
	}


	return s.substr(0, is) == t.substr(0, it);
}

int main(int argc, char const *argv[]) {
	string s, t;
	cin >> s >> t;

	cout << backspaceCompare(s, t);

	return 0;
}