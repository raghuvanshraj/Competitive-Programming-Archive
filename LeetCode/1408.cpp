/**
 *    author:	vulkan
 *    created:	23.01.2022 10:22:59 AM
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> compute_lps(string t) {
	int m = t.size();
	vector<int> lps(m + 1);
	int i = 2;
	int len = 0;
	while (i <= m - 1) {
		if (t[i - 1] == t[len]) {
			lps[i++] = ++len;
		} else {
			if (len != 0) {
				len = lps[len];
			} else {
				lps[i++] = 0;
			}
		}
	}

	return lps;
}

bool check(string s, int l, int r) {
	return (s[l - 1] != '?' or s[r + 1] != '?');
}

bool kmp(string s, string t) {
	vector<int> lps = compute_lps(t);

	int n = s.size();
	int m = t.size();
	int i = 0;
	int j = 0;
	while (true) {
		if (j == m) {
			if (check(s, i - j, i - 1)) {
				return true;
			}
			j = 0;
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

	return false;
}

vector<string> stringMatching(vector<string> &words) {
	int n = words.size();
	string s = "";
	for (int i = 0; i <= n - 1; ++i) {
		s = s + "?" + words[i];
	}
	s = s + "?";

	vector<string> ans;
	for (int i = 0; i <= n - 1; ++i) {
		if (kmp(s, words[i])) {
			ans.push_back(words[i]);
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<string> words(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> words[i];
	}

	vector<string> ans = stringMatching(words);
	for (string x : ans) {
		cout << x << endl;
	}

	return 0;
}