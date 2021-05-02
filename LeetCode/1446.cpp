/**
 *    author:	vulkan
 *    created:	16.05.2020 10:10:46 PM
**/
#include <bits/stdc++.h>

using namespace std;

int maxPower(string s) {
	char curr_char = s[0];
	int curr_pow = 1;
	int ans = 1;
	int n = s.size();
	for (int i = 1; i <= n - 1; ++i) {
		if (s[i] == curr_char) {
			curr_pow++;
		} else {
			ans = max(ans, curr_pow);
			curr_pow = 1;
			curr_char = s[i];
		}
	}

	ans = max(ans, curr_pow);

	return ans;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	cout << maxPower(s);

	return 0;
}