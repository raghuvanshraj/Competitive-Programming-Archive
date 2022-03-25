/**
 *    author:	vulkan
 *    created:	27.02.2022 08:25:56 AM
**/
#include <bits/stdc++.h>

using namespace std;

string repeatLimitedString(string s, int r) {
	map<char, char> smaller;
	map<char, int> cnt;
	int n = s.size();
	sort(s.begin(), s.end());
	for (int i = 1; i <= n - 1; ++i) {
		if (s[i] != s[i - 1]) {
			smaller[s[i]] = s[i - 1];
		}
		cnt[s[i]]++;
	}

	string ans(n + 1, ' ');
	int i = 1;
	auto it = cnt.rbegin();
	int curr_cnt = 0;
	while (it != cnt.rend()) {
		// cout << it->first << endl;
		// we can place current character
		// we have to place smaller character
		// we can place smaller character
		// we cannot place smaller character

		if (it->second == 0) {
			it++;
			continue;
		}

		while (smaller.count(it->first) and cnt[smaller[it->first]] == 0) {
			smaller[it->first] = smaller[smaller[it->first]];
		}

		char c = (curr_cnt < r) ? it->first : smaller[it->first];
		ans[i] = c;
		cnt[c]--;
		if (ans[i] == ans[i - 1]) {
			curr_cnt++;
		} else {
			curr_cnt = 1;
		}
		i++;

		cout << it->first << ' ' << curr_cnt << endl;
		cout << ans << endl;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	string s;
	int r;
	cin >> s >> r;

	cout << repeatLimitedString(s, r);

	return 0;
}