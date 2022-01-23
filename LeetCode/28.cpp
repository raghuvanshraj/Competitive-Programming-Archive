/**
 *    author:	vulkan
 *    created:	22.01.2022 11:11:04 PM
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

int strStr(string s, string t) {
	int n = s.size();
	int m = t.size();

	vector<int> lps = compute_lps(t);

	int i = 0, j = 0;
	while (true) {
		if (j == m) {
			return i - j;
		}
		if (i == n) {
			break;
		}

		if (s[i] == t[j]) {
			i++;
			j++;
		} else {
			if (j == 0) {
				i++;
			} else {
				j = lps[j];
			}
		}
	}

	return -1;
}

int main(int argc, char const *argv[]) {
	string s, t;
	cin >> s >> t;

	cout << strStr(s, t);

	return 0;
}