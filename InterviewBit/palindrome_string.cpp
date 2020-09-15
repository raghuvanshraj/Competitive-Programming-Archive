#include <bits/stdc++.h>

using namespace std;

string process_string(string s) {
	int n = s.size();
	string new_string = "";
	for (int i = 0; i < n; ++i) {
		if ((s[i] >= 'A' and s[i] <= 'Z') or
			(s[i] >= 'a' and s[i] <= 'z') or
			(s[i] >= '0' and s[i] <= '9')) {
			new_string = new_string + s.substr(i,1);
		}
	}

	transform(new_string.begin(), new_string.end(), new_string.begin(), ::tolower);

	return new_string;
}

bool isPalindrome(string s) {
	s = process_string(s);
	// cout << s << endl;
	int n = s.size();
	int i = 0, j = n-1;
	while (i <= j) {
		if (s[i] == s[j]) {
			i++;
			j--;
		} else {
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[]) {
	string s;
	getline(cin, s);
	cout << isPalindrome(s);
	return 0;
}