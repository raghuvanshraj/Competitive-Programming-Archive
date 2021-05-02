#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

bool dilemma(string s) {
	int n = s.size();
	bool *left_original = new bool[n]();
	bool *left_flip = new bool[n]();
	bool *right_original = new bool[n]();
	bool *right_flip = new bool[n]();

	left_original[0] = (s[0] - '0') ? true : false;
	left_flip[0] = not left_original[0];
	right_original[n-1] = (s[n-1] - '0') ? true : false;
	right_flip[n-1] = not right_original[n-1];

	for (int i = 1; i < n; ++i) {
		if (s[i] - '0') {
			left_original[i] = left_flip[i-1];
			left_flip[i] = left_original[i-1];
		} else {
			left_original[i] = left_original[i-1];
			left_flip[i] = left_flip[i-1];
		}
	}

	for (int i = n-2; i >= 0; --i) {
		if (s[i] - '0') {
			right_original[i] = right_flip[i+1];
			right_flip[i] = right_original[i+1];
		} else {
			right_original[i] = right_original[i+1];
			right_flip[i] = right_flip[i+1];
		}
	}

	for (int i = 0; i < n; ++i) {
		if (left_original[i] and right_original[i] and s[i] == '1') {
			return true;
		}
	}

	return false;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		bool can_win = dilemma(s);
		string ans = (can_win) ? "WIN" : "LOSE";
		cout << ans << endl;
	}
	return 0;
}
