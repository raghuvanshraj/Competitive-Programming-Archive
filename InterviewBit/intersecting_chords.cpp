#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int chordCnt(int n) {
	n *= 2;
	long *dp = new long[n+1]();
	dp[0] = 1;
	dp[2] = 1;
	for (int i = 4; i < n+1; i += 2) {
		for (int j = 0	; j < i-1; j += 2) {
			dp[i]  = (dp[i] + (dp[j] * dp[i-j-2]) % MOD) % MOD;
		}
	}
	
	return dp[n];
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	cout << chordCnt(n);
	return 0;
}