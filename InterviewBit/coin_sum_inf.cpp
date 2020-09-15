#include <bits/stdc++.h>
#define MOD 1000007

using namespace std;

int coinchange2(vector<int> &coins, int sum) {
	int n = coins.size();
    int *dp = new int[sum+1]();
    dp[0] = 1;
    for (int i = 1; i < n+1; ++i) {
        for (int j = 0; j < sum+1; ++j) {
            if (j + coins[i-1] <= sum) {
                dp[j + coins[i-1]] = (dp[j + coins[i-1]] + dp[j]) % MOD;
            }
        }
    }

    return dp[sum];
}

int main(int argc, char const *argv[]) {
	int n,s;
	cin >> n >> s;
	vector<int> coins(n);
	for (int i = 0; i < n; ++i) {
		cin >> coins[i];
	}

	cout << coinchange2(coins, s);
	
	return 0;
}