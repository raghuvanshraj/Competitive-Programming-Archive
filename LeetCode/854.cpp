/**
 *    author:	vulkan
 *    created:	24.05.2020 03:45:06 PM
**/
#include <bits/stdc++.h>

using namespace std;

int kSimilarity(string s, string t) {
	int n = s.size();
	if (n == 0) {
		return 0;
	}

	for (int i = 0; i <= n - 1; ++i) {
		if (s[i] != t[i]) {
			vector<int> idx;
			for (int j = 0; j <= n - 1; ++j) {
				if (s[j] == t[i] and s[j] != t[j]) {
					idx.push_back(j);
				}
			}

			int curr_ans = INT_MAX;
			for (int j : idx) {
				swap(s[i], s[j]);
				curr_ans = min(curr_ans, 1 + kSimilarity(s.substr(i + 1), t.substr(i + 1)));
				swap(s[i], s[j]);
			}

			return curr_ans;
		}
	}

	return 0;
}

int main(int argc, char const *argv[]) {
	string s, t;
	cin >> s >> t;

	cout << kSimilarity(s, t);

	return 0;
}