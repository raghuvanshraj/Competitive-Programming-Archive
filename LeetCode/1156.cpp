/**
 *    author:	vulkan
 *    created:	18.06.2020 05:46:57 PM
**/
#include <bits/stdc++.h>

using namespace std;

int maxRepOpt1(string s) {
	map<char, int> cnt;
	for (char x : s) {
		cnt[x]++;
	}

	map<char, int> ans;
	int n = s.size();
	for (pair<char, int> p : cnt) {
		char ch = p.first;
		int i = 0;
		while (i < n) {
			if (s[i] == ch) {
				break;
			}

			i++;
		}

		int j = i;
		int curr_ans = 0;
		int diff_idx = -1;
		while (j < n) {
			if (s[j] == ch) {
				if (j - i + 1 > curr_ans) {
					if (diff_idx != -1) {
						curr_ans = j - i;
					} else {
						curr_ans = j - i + 1;
					}
				}
			} else {
				if (diff_idx == -1) {
					diff_idx = j;
				} else {
					i = diff_idx + 1;
					diff_idx = j;
				}
			}

			j++;
		}

		if (curr_ans < cnt[ch]) {
			ans[ch] = curr_ans + 1;
		} else {
			ans[ch] = curr_ans;
		}
	}

	int max_ans = INT_MIN;
	for (pair<char, int> p : ans) {
		max_ans = max(p.second, max_ans);
	}

	return max_ans;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	cout << maxRepOpt1(s);

	return 0;
}