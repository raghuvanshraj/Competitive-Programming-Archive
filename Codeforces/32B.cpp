#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == '.') {
			cout << 0;
		} else {
			if (i < n-1) {
				if (s[++i] == '.') {
					cout << 1;
				} else {
					cout << 2;
				}
			}
		}
	}

	return 0;
}