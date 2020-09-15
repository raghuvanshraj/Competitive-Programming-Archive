#include <bits/stdc++.h>
#define MOD 10000003

using namespace std;

string removeSpaces(string s) {
	int n = s.size();
	string res = "";
	for (int i = 0; i < n; i += 2) {
		res = res + s.substr(i,1);
	}

	return res;
}

int seats(string s) {
	vector<int> seatIndices;
	int n = s.size();
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'x') {
			seatIndices.push_back(i);
		}
	}

	for (int i = 0; i < seatIndices.size(); ++i) {
		cout << seatIndices[i] << ' ';
	}

	cout << endl << endl;

	int m = seatIndices.size();
	int mid = m / 2, ans = 0, k = 1;
	for (int i = mid+1; i < m; ++i) {
		ans = (ans + seatIndices[i] - seatIndices[mid] - k++) % MOD;
	}

	k = 1;
	for (int i = mid-1; i >= 0; --i) {
		ans = (ans + seatIndices[mid] - seatIndices[i] - k++) % MOD;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	string s;
	getline(cin, s);
	s = removeSpaces(s);
	cout << seats(s);
	return 0;
}