/**
 *    author:	vulkan
 *    created:	23.01.2022 10:20:08 AM
**/
#include <bits/stdc++.h>

using namespace std;

bool rotateString(string s, string t) {
	return (s.size() == t.size()) and (s + s).find(t) != string::npos;
}

int main(int argc, char const *argv[]) {
	string s, t;
	cin >> s >> t;

	cout << rotateString(s, t);

	return 0;
}