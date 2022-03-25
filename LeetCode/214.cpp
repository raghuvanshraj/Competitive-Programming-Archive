/**
 *    author:	vulkan
 *    created:	25.02.2022 12:41:20 PM
**/
#include <bits/stdc++.h>

using namespace std;

int lps(string s) {
	int m = s.size();
	vector<int> pi(m + 1);
	int i = 2;
	int len = 0;
	while (i <= m) {
		if (s[i - 1] == s[len]) {
			pi[i++] = ++len;
		} else {
			if (len != 0) {
				len = pi[len];
			} else {
				pi[i++] = 0;
			}
		}
	}

	return pi[m];
}

string shortestPalindrome(string s) {
	string t(s);
	reverse(s.begin(), s.end());
	t = t + "?" + s;

	cout << lps(t);

	return "";
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	cout << shortestPalindrome(s);

	return 0;
}