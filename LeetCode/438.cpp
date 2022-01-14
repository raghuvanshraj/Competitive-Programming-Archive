/**
 *    author:	vulkan
 *    created:	13.01.2022 08:15:00 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &s_cnt, vector<int> &p_cnt) {
	for (int i = 0; i <= 25; ++i) {
		if (p_cnt[i] != 0 and s_cnt[i] != p_cnt[i]) {
			return false;
		}
	}

	return true;
}

vector<int> findAnagrams(string s, string p) {
	int n = s.size();
	int m = p.size();
	if (n < m) {
		return vector<int>();
	}

	set<char> elems(p.begin(), p.end());
	int unq_elems = elems.size();
	vector<int> s_cnt(26), p_cnt(26);

	for (char x : p) {
		p_cnt[x - 'a']++;
	}

	for (int i = 0; i <= m - 2; ++i) {
		s_cnt[s[i] - 'a']++;
	}

	int i = 0, j = m - 1;
	vector<int> ans;
	while (j <= n - 1) {
		s_cnt[s[j++] - 'a']++;

		if (check(s_cnt, p_cnt)) {
			ans.push_back(i);
		}

		s_cnt[s[i++] - 'a']--;
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