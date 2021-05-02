/**
 *    author:	vulkan
 *    created:	07.03.2020 10:08:19 PM
**/
#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
	int n = s.size();
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	}

	unordered_map<int, int> last_idx;
	last_idx[s[0]] = 1;

	int i = 0, j = 1;
	int max_len = 1;
	while (j < n) {
		if (last_idx[s[j]] != 0) {
			int new_i = last_idx[s[j]];
			while (i < new_i) {
				last_idx[s[i]] = 0;
				++i;
			}
		}

		last_idx[s[j]] = j + 1;
		max_len = max(max_len, j - i + 1);
		++j;
	}

	return max_len;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	cout << lengthOfLongestSubstring(s);

	return 0;
}