#include <bits/stdc++.h>

using namespace std;

int maxR(string s) {

	if (s.find('K') == s.npos) {
		
		return s.size()-1;
	}

	int curr = 0;
	int best = 0;
	int count = 0;

	for (int i = 0; i < s.size(); ++i) {
		
		curr += (s[i] == 'R') ? -1 : 1;
		curr = (curr < 0) ? 0 : curr;
		best = max(curr, best);
		count += (s[i] == 'R') ? 1 : 0;
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