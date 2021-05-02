#include <bits/stdc++.h>

using namespace std;

unordered_map<long,long> dp;

long byteland(long n) {
	if (n == 0) {
		return 0;
	}

	if (dp[n] != 0) {
		return dp[n];
	}

	dp[n] = max(byteland(n/2) + byteland(n/3) + byteland(n/4),
			   n);

	return dp[n];
}

int main(int argc, char const *argv[]) {
	string line;
	while (getline(cin, line)) {
		long num = stol(line);
		cout << byteland(num) << endl;
	}

	return 0;
}
