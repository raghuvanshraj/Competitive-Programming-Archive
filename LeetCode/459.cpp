/**
 *    author:	vulkan
 *    created:	23.01.2022 09:46:25 AM
**/
#include <bits/stdc++.h>

using namespace std;

bool repeatedSubstringPattern(string s) {
	string t = s + s;
	int n = t.size();
	return t.substr(1, n - 2).find(s) != t.npos;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;

	cout << repeatedSubstringPattern(s);

	return 0;
}