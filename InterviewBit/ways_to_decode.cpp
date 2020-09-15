#include <bits/stdc++.h>

using namespace std;

bool check2Digit(string num) {
	int intNum = 10 * (num[0] - '0') + (num[1] - '0');
	if (intNum >= 10 and intNum <= 26) {
		return true;
	}

	return false;
}

int numDecodings(string num) {
	if (num[0] == '0') {
		return 0;
	}
	
	int n = num.size();
	int *dp = new int[n+1]();
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i < n+1; ++i) {
		if (num[i-1] != '0') {
			dp[i] = dp[i-1];
		}
		if (check2Digit(num.substr(i-2, 2))) {
			dp[i] += dp[i-2];
		}
	}

	return dp[n];
}

int main(int argc, char const *argv[]) {
	string num;
	cin >> num;
	cout << numDecodings(num);
	return 0;
}