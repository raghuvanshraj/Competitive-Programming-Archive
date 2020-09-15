#include <bits/stdc++.h>

using namespace std;

int maxR(string s) {
	if (s.find('K') == s.npos) {
		return s.size()-1;
	}

	int currMax = 0;
	int best = 0;
	int count = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (currMax < 0) {
			currMax = 0;
		}
		if (s[i] == 'K') {
			currMax++;
		} else {
			currMax--;
			count++;
		}

		best = max(best, currMax);
	}

	return count + best;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		cout << maxR(s) << endl;
	}
	return 0;
}