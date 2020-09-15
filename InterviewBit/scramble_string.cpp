#include <bits/stdc++.h>

using namespace std;

bool solve(string s1, string s2) {
	int n = s1.size(), m = s2.size();
	if (n != m) {
		return false;
	}

	if (n == 1) {
		return (s1[0] == s2[0]);
	}

	int mid = n/2;
	string s1_left = s1.substr(0, mid), s1_right = s1.substr(mid);
	string s2_left = s2.substr(0, mid), s2_right = s2.substr(mid);

	return (solve(s1_left, s2_left) and solve(s1_right, s2_right)) or
			(solve(s1_left, s2_right) and solve(s1_right, s2_left));
}

int main(int argc, char const *argv[]) {
	string s1,s2;
	cin >> s1 >> s2;

	cout << solve(s1,s2);
	
	return 0;
}