/**
 *    author:	vulkan
 *    created:	10.03.2020 06:57:21 PM
**/
#include <bits/stdc++.h>

using namespace std;

string removeDuplicateLetters(string s) {
	string ans = "";
	vector<int> counts(26);

	int n = s.size();
	for (int i = 0; i < n; ++i) {
		counts[s[i] - 'a']++;
	}

	vector<bool> visited(26);
	for (int i = 0; i < n; ++i) {
		counts[s[i] - 'a']--;
		if (visited[s[i] - 'a']) {
			continue;
		}

		int m = ans.size();
		while (m > 0 and s[i] < ans[m - 1] and counts[ans[m - 1] - 'a'] > 0) {
			visited[ans[--m] - 'a'] = false;
		}

		ans = ans.substr(0, m);
		ans = ans + s.substr(i, 1);
		visited[s[i] - 'a'] = true;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	cout << removeDuplicateLetters(s);

	return 0;
}