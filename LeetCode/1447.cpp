/**
 *    author:	vulkan
 *    created:	16.05.2020 10:15:31 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<string> simplifiedFractions(int n) {
	vector<string> ans;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= i - 1; ++j) {
			if (__gcd(i, j) == 1) {
				string num = to_string(j);
				string den = to_string(i);

				ans.push_back(num + "/" + den);
			}
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;

	vector<string> ans = simplifiedFractions(n);
	for (string s : ans) {
		cout << s << endl;
	}

	return 0;
}