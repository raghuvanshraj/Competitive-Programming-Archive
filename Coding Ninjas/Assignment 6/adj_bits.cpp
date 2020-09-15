#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;

ull adjBitCount(int n, int k)
{
	ull dp[n+1][k+1][2];
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 1; j < k+1; ++j)
		{
			dp[i][j][0] = 0;
			dp[i][j][1] = 0;
		}
	}
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	for (int i = 2; i < n+1; ++i)
	{
		dp[i][0][0] = (dp[i-1][0][0]+dp[i-1][0][1]) % MOD;
		dp[i][0][1] = dp[i-1][0][0];
	}
	for (int i = 2; i < n+1; ++i)
	{
		for (int j = 1; j < k+1; ++j)
		{
			dp[i][j][1] = (dp[i-1][j][0]+dp[i-1][j-1][1]) % MOD;
			dp[i][j][0] = (dp[i-1][j][0]+dp[i-1][j][1]) % MOD;
		}
	}

	return (dp[n][k][0]+dp[n][k][1]) % MOD;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		int i;
		int n;
		int k;
		cin >> i >> n >> k;
		cout << i << " " << adjBitCount(n,k) << endl;
	}
	return 0;
}