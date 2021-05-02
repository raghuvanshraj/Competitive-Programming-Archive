/**
 *    author:	vulkan
 *    created:	16.04.2020 02:56:19 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool checkValidString(string s) {
	int l = 0, h = 0;
	for (char c : s) {
		if (c == '(') {
			l++;
			h++;
		} else if (c == ')') {
			if (l > 0) {
				l--;
			}

			h--;
		} else {
			if (l > 0) {
				l--;
			}

			h++;
		}

		if (h < 0) {
			return false;
		}
	}

	return l == 0;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	cout << checkValidString(s);

	return 0;
}