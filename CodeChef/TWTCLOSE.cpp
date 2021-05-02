#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int n,k;
	cin >> n >> k;
	bool *tweets = new bool[n]();
	int openCount = 0;
	while (k--) {
		string type;
		cin >> type;
		if (type == "CLICK") {
			int tweet;
			cin >> tweet;
			tweets[tweet-1] = not tweets[tweet-1];
			openCount = (tweets[tweet-1]) ? openCount + 1 : openCount - 1;
			cout << openCount << endl;
		} else {
			for (int i = 0; i < n; ++i) {
				tweets[i] = false;
			}
			openCount = 0;
			cout << openCount << endl;
		}
	}
	return 0;
}