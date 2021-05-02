/**
 *    author:	vulkan
 *    created:	19.05.2020 11:33:00 PM
**/
#include <bits/stdc++.h>

using namespace std;

string minWindow(string s, string t) {
	int n = s.size();
	map<char, int> counts;
	for (char c : t) {
		counts[c]++;
	}
	int m = counts.size();

	int i = 0, j = 0;
	int start_idx = -1, len = INT_MAX;
	while (j < n) {
		if (m > 0) {
			if (counts.count(s[j])) {
				counts[s[j]]--;
				if (counts[s[j]] == 0) {
					m--;
				}
			}

			j++;
		} else if (m == 0) {
			if (len > j - i) {
				len = j - i;
				start_idx = i;
			}

			if (counts.count(s[i])) {
				counts[s[i]]++;
				if (counts[s[i]] > 0) {
					m++;
				}
			}

			i++;
		}
	}

	while (i < n) {
		if (m == 0) {
			if (len > j - i) {
				len = j - i;
				start_idx = i;
			}
		}

		if (counts.count(s[i])) {
			counts[s[i]]++;
			if (counts[s[i]] > 0) {
				m++;
			}
		}

		i++;
	}

	if (start_idx == -1) {
		return "";
	}

	return s.substr(start_idx, len);
}

int main(int argc, char const *argv[]) {
	string s, t;
	cin >> s >> t;

	cout << minWindow(s, t);

	return 0;
}