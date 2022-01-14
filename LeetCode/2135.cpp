/**
 *    author:	vulkan
 *    created:	14.01.2022 10:46:45 PM
**/
#include <bits/stdc++.h>

using namespace std;

int wordCount(vector<string> &s_words, vector<string> &t_words) {
	int m = t_words.size();
	vector<vector<int>> pre_cnt(26, vector<int>(m));
	int n = s_words.size();
	for (int i = 0; i <= n - 1; ++i) {
		vector<int> cnt(26);
		for (char c : s[i]) {
			int x = c - 'a';
			cnt[x]++;
			pre_cnt[c][cnt[x]]++;
		}
	}
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<string> s_words(n), t_words(m);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> s_words[i];
	}
	for (int i = 0; i <= m - 1; ++i) {
		cin >> t_words[i];
	}

	cout << wordCount(s_words, t_words);

	return 0;
}