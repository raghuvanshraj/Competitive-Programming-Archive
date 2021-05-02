/**
 *    author:	vulkan
 *    created:	25.03.2020 01:55:46 AM
**/
#include <bits/stdc++.h>

using namespace std;

int longestSubstring(string s, int k) {
	if (s.empty()) {
		return 0;
	}

	map<char, int> counts;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		counts[s[i]]++;
	}

	int ans = INT_MIN;
	int curr = 0;
	for (int i = 0; i < n; ++i) {
		if (counts[s[i]] < k) {
			ans = max(ans, longestSubstring(s.substr(curr, i - curr), k));
			curr = i + 1;
		}
	}

	if (curr != 0) {
		ans = max(ans, longestSubstring(s.substr(curr), k));
	}

	if (ans == INT_MIN) {
		return n;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;
	int k;
	cin >> k;

	cout << longestSubstring(s, k);

	return 0;
}