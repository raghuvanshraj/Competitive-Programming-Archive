/**
 *    author:	vulkan
 *    created:	23.01.2022 11:59:18 AM
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

bool check(string s, int l) {
	return (l == 0 or s[l - 1] == ' ');
}

int kmp(string s, string t) {
	vector<int> lps = compute_lps(t);

	int n = s.size();
	int m = t.size();
	int i = 0;
	int j = 0;
	int cnt = 1;
	while (true) {
		if (j == m) {
			if (check(s, i - j)) {
				return cnt;
			}
			j = 0;
		}
		if (i == n) {
			break;
		}

		if (s[i] == ' ') {
			i++;
			cnt++;
		} else if (s[i] == t[j]) {
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

	return -1;
}

int isPrefixOfWord(string sentence, string word) {
	return kmp(sentence, word);
}

int main(int argc, char const *argv[]) {
	string sentence;
	getline(cin, sentence);
	string search;
	cin >> search;

	cout << isPrefixOfWord(sentence, search);

	return 0;
}