/**
 *    author:	vulkan
 *    created:	17.05.2020 10:52:30 AM
**/
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string s, char c = ' ') {
	vector<string> ans;
	int start_idx = 0;
	int n = s.size();
	for (int i = 0; i <= n - 1; ++i) {
		if (s[i] == c) {
			ans.push_back(s.substr(start_idx, i - start_idx));
			start_idx = i + 1;
		}
	}

	if (start_idx < n) {
		ans.push_back(s.substr(start_idx));
	}

	return ans;
}

static bool comp(string s, string t) {
	return s.size() < t.size();
}

string arrangeWords(string s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	vector<string> split = split_string(s);
	stable_sort(split.begin(), split.end(), comp);

	int n = s.size();
	string ans(n, ' ');
	int i = 0;
	int m = split.size();
	for (int j = 0; j <= m - 1; ++j) {
		for (char c : split[j]) {
			ans[i++] = c;
		}
		if (j < n - 1) {
			ans[i++] = ' ';
		}
	}

	ans[0] = toupper(ans[0]);

	return ans;
}

int main(int argc, char const *argv[]) {
	string s;
	getline(cin, s);
	getline(cin, s);

	cout << arrangeWords(s);

	return 0;
}