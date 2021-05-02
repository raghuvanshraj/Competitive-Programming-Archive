/**
 *    author:	raghuvanshraj
 *    created:	17.11.2020 03:52:20 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool closeStrings(string a, string b) {
	map<int, int> cnta, cntb;
	for (char x : a) {
		cnta[x]++;
	}
	for (char x : b) {
		cntb[x]++;
	}

	vector<int> va(cnta.size()), vb(cntb.size());
	for (auto p : cnta) {
		va.push_back(p.second);
	}
	for (auto p : cntb) {
		vb.push_back(p.second);
	}

	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	if (va.size() == vb.size()) {
		int n = va.size();
		for (int i = 0; i <= n - 1; ++i) {
			if (va[i] != vb[i]) {
				return false;
			}
		}

		auto ita = cnta.begin(), itb = cntb.begin();
		while (ita != cnta.end()) {
			if (ita->first != itb->first) {
				return false;
			}
			ita++;
			itb++;
		}

		return true;
	}

	return false;
}

int main(int argc, char const *argv[]) {
	string a, b;
	cin >> a >> b;
	cout << closeStrings(a, b);

	return 0;
}