#include <bits/stdc++.h>

using namespace std;

int solve(string s) {
	int n = s.size();
	int i = 0, j = n-1;
	int count = 0;
	while (i <= j) {
		if (s[i] == s[j]) {
			i++;
			j--;
		} else {
			count++;
			j--;
		}
	}

	return count;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;
	cout << solve(s);
	return 0;
}