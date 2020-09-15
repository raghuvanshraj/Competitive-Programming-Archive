#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;
	int *dp = new int[s.size()]();
	dp[s.size()-1] = ((s[s.size()-1] - '0') % 2 == 0);
	for (int i = s.size()-2; i >= 0; --i) {
		dp[i] = dp[i+1];
		if ((s[i] - '0') % 2 == 0) {
			dp[i]++;
		}
	}
	for (int i = 0; i < s.size(); ++i) {
		cout << dp[i] << ' ';
	}
	return 0;
}