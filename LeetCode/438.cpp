/**
 *    author:	vulkan
 *    created:	13.01.2022 08:15:00 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> findAnagrams(string s, string p) {
	int n = s.size();
	int m = p.size();
	if (n < m) {
		return vector<int>();
	}

	vector<int> s_cnt(26), p_cnt(26);
	for (char x : p) {
		p_cnt[x - 'a']++;
	}

	set<int> elems(p.begin(), p.end());
	int unq_elems = elems.size();
	int cnt = 0;
	for (int i = 0; i <= m - 2; ++i) {
		int x = s[i] - 'a';
		s_cnt[x]++;
		if (s_cnt[x] == p_cnt[x]) {
			cnt++;
		} else if (s_cnt[x] > p_cnt[x] and p_cnt[x] != 0) {
			cnt--;
		}
	}

	int i = 0, j = m - 1;
	vector<int> ans;
	while (j <= n - 1) {
		int x = s[j++] - 'a';
		s_cnt[x]++;
		if (s_cnt[x] == p_cnt[x]) {
			cnt++;
		} else if (s_cnt[x] > p_cnt[x] and p_cnt[x] != 0) {
			cnt--;
		}

		if (cnt == unq_elems) {
			ans.push_back(i);
		}

		int y = s[i++] - 'a';
		// cout << s.substr(i - 1, m) << ' ' << cnt << ' ' << s_cnt[x] << ' ' << p_cnt[y] << endl;
		if (s_cnt[y] == p_cnt[y]) {
			cnt--;
		}
		s_cnt[y]--;
		if (s_cnt[y] == p_cnt[y] and p_cnt[y] != 0) {
			cnt++;
		}
	}

	if (cnt == unq_elems) {
		ans.push_back(i);
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	string s;
	string p;
	cin >> s >> p;

	vector<int> ans = findAnagrams(s, p);
	for (int x : ans) {
		cout << x << ' ';
	}

	return 0;
}