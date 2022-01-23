/**
 *    author:	vulkan
 *    created:	23.01.2022 12:08:18 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> compute_lps(string s) {
	int n = s.size();
	vector<int> lps(n + 1);
	int len = 0;
	int i = 2;
	while (i <= n) {
		if (s[i - 1] == s[len]) {
			lps[i++] = ++len;
		} else {
			if (len != 0) {
				len = lps[len];
			} else {
				i++;
			}
		}
	}

	return lps;
}

vector<int> kmp(string s, string t) {
	vector<int> lps = compute_lps(t);

	int n = s.size();
	int m = t.size();
	int i = 0;
	int j = 0;
	vector<int> match(n);
	while (true) {
		if (j == m) {
			match[i - 1]++;
			j = lps[j];
		}
		if (i == n) {
			break;
		}

		if (s[i] == t[j]) {
			i++;
			j++;
		} else {
			if (j != 0) {
				j = lps[j];
			} else {
				i++;
			}
		}
	}

	return match;
}

int maxRepeating(string s, string t) {
	vector<int> match = kmp(s, t);
	int n = s.size();
	int m = t.size();
	int cnt = 0;
	for (int i = 0; i <= n - 1; ++i) {
		if (match[i] and i >= m and match[i - m]) {
			match[i] += match[i - m];
		}
	}

	return *max_element(match.begin(), match.end());
}

int main(int argc, char const *argv[]) {
	string s, t;
	cin >> s >> t;

	cout << maxRepeating(s, t);

	return 0;
}