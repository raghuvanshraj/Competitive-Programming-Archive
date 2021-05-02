/**
 *    author:	vulkan
 *    created:	24.08.2020 10:42:30 AM
**/
#include <bits/stdc++.h>

using namespace std;

string customSortString(string s, string t) {
	map<char, int> cnt;
	for (char c : t) {
		cnt[c]++;
	}

	int n = s.size(), m = t.size();
	string ans(m, ' ');
	int i = 0, j = 0;
	while (i < n) {
		while (cnt[s[i]]--) {
			ans[j++] = s[i];
		}
		i++;
	}

	for (auto x : cnt) {
		if (x.second > 0) {
			while (x.second--) {
				ans[j++] = x.first;
			}
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	string s, t;
	cin >> s >> t;

	cout << customSortString(s, t);

	return 0;
}