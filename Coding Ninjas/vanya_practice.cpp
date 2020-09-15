#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;

ull vanya(int *input, int n)
{
	ull dp[n][101];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 101; ++j)
		{
			dp[i][j] = 0;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		dp[i][input[i]] = 1;
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (input[j] < input[i])
			{
				for (int k = 0; k < input[j]+1; ++k)
				{
					dp[i][__gcd(k,input[i])] = (dp[i][__gcd(k,input[i])] + dp[j][k]) % MOD;
				}
			}
		}
	}

	ull ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = (ans + dp[i][1]) % MOD;
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *input = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}

	cout << vanya(input,n);
	return 0;
}