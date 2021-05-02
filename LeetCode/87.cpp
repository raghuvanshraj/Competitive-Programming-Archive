/**
 *    author:	vulkan
 *    created:	09.03.2020 08:09:15 PM
**/
#include <bits/stdc++.h>

using namespace std;

map<pair<string, string>, bool> dp;

bool isScramble(string s1, string s2) {
	// cout << s1 << ' ' << s2 << endl;
	if (s1 == s2) {
		return true;
	}

	if (s1.empty() and s2.empty()) {
		return true;
	}

	if (s1.empty() or s2.empty()) {
		return false;
	}

	int n = s1.size(), m = s2.size();
	if (n != m) {
		return false;
	} else {
		if (n == 1) {
			return s1 == s2;
		}
	}

	if (dp.find({s1, s2}) != dp.end()) {
		return dp[ {s1, s2}];
	}

	if (n % 2) {
		dp[ {s1, s2}] = (
		                    (isScramble(s1.substr(0, n / 2), s2.substr(0, m / 2)) and isScramble(s1.substr(n / 2), s2.substr(m / 2))) or
		                    (isScramble(s1.substr(0, n / 2 + 1), s2.substr(0, m / 2 + 1)) and isScramble(s1.substr(n / 2 + 1), s2.substr(m / 2 + 1))) or
		                    (isScramble(s1.substr(0, n / 2), s2.substr(m / 2 + 1)) and isScramble(s1.substr(n / 2), s2.substr(0, m / 2 + 1))) or
		                    (isScramble(s1.substr(0, n / 2 + 1), s2.substr(m / 2)) and isScramble(s1.substr(n / 2 + 1), s2.substr(0, m / 2)))
		                );
	} else {
		dp[ {s1, s2}] = (
		                    (isScramble(s1.substr(0, n / 2), s2.substr(0, m / 2)) and isScramble(s1.substr(n / 2), s2.substr(m / 2))) or
		                    (isScramble(s1.substr(0, n / 2), s2.substr(m / 2)) and isScramble(s1.substr(n / 2), s2.substr(0, m / 2)))
		                );
	}

	// cout << s1 << ' ' << s2 << ": " << dp[{s1,s2}] << endl;

	return dp[ {s1, s2}];
}

int main(int argc, char const *argv[]) {
	string s1, s2;
	cin >> s1 >> s2;

	cout << isScramble(s1, s2);

	return 0;
}