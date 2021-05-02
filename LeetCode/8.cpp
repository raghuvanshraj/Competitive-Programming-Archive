/**
 *    author:	vulkan
 *    created:	02.11.2019 10:21:53 AM
**/
#include <bits/stdc++.h>

using namespace std;

int myAtoi(string s) {
	int n = s.size();
	long num = 0;
	int i = 0;
	while (i < n and s[i] == ' ') {
		i++;
	}

	bool is_neg = (s[i] == '-');
	if (s[i] == '-' or s[i] == '+') {
		i++;
	}

	while (i < n and s[i] <= '9' and s[i] >= '0') {
		if (is_neg) {
			num = (num * 10L - (long)(s[i] - '0'));
			if (num < INT_MIN) {
				return INT_MIN;
			}
		} else {
			num = (num * 10L + (long)(s[i] - '0'));
			if (num > INT_MAX) {
				return INT_MAX;
			}
		}

		i++;
	}

	return num;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	cout << myAtoi(s);

	return 0;
}