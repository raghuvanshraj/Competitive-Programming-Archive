#include <bits/stdc++.h>
#define MOD	1000000007

using namespace std;
typedef unsigned long long ull;

unordered_map<string, int> code;

ull alphaCode(string s) {
	if (s.size() == 0) {
		return 1;
	}
	if (s[0] == '0') {
		return 0;
	}
	if (s.size() == 1) {
		return 1;
	}
	if (code[s] > 0) {
		return code[s];
	}

	ull ans = 0;
	if (s[0] != '0') {
		ans = alphaCode(s.substr(1));
	}

	int num = (s[0] - '0') * 10 + (s[1] - '0');
	if (num >= 10 and num <= 26) {
		ans = (ans + alphaCode(s.substr(2))) % MOD;
	}

	code[s] = ans % MOD;
	return code[s];
}

int main(int argc, char const *argv[]) {
	while (true) {
		string s;
		cin >> s;
		if (s == "0") {
			break;
		}

		cout << alphaCode(s) << endl;
	}
	return 0;
}