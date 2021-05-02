/**
 *    author:	vulkan
 *    created:	05.03.2020 01:59:40 PM
**/
#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s) {
	int max_len = INT_MIN;
	string ans = "";

	int n = s.size();
	for (int i = 0; i < n; ++i) {
		int low = i, high = i;
		while (low >= 0 and high < n and s[low] == s[high]) {
			if (max_len < high - low + 1) {
				max_len = high - low + 1;
				ans = s.substr(low, max_len);
			}

			low--;
			high++;
		}
	}

	for (int i = 0; i < n - 1; ++i) {
		int low = i, high = i + 1;
		while (low >= 0 and high < n and s[low] == s[high]) {
			if (max_len < high - low + 1) {
				max_len = high - low + 1;
				ans = s.substr(low, max_len);
			}

			low--;
			high++;
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	string ans = longestPalindrome(s);

	cout << ans;

	return 0;
}