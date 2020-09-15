#include <bits/stdc++.h>

using namespace std;

bool subsetSumK(int *input, int n, int k)
{
	bool dp[n+1][k+1];
	for (int i = 0; i < k+1; ++i)
	{
		dp[0][i] = false;
	}
	for (int i = 0; i < n+1; ++i)
	{
		dp[i][0] = true;
	}

	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < k+1; ++j)
		{
			if (j >= input[i-1])
			{
				dp[i][j] = dp[i-1][j-input[i-1]] or dp[i-1][j];
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][k];
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
	int k;
	cin >> k;
	bool ans = subsetSumK(input,n,k);
	string out = (ans) ? "Yes" : "No";
	cout << out;

	return 0;
}