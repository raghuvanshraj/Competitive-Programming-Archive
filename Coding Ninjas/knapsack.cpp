#include <bits/stdc++.h>

using namespace std;

int knapsack(int *weights, int *values, int n, int maxWeight)
{
	int dp[n+1][maxWeight+1];
	for (int i = 0; i < n+1; ++i)
	{
		dp[i][0] = 0;
	}
	for (int i = 0; i < maxWeight+1; ++i)
	{
		dp[0][i] = 0;
	}

	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < maxWeight+1; ++j)
		{
			if (weights[i-1] <= j)
			{
				dp[i][j] = max(values[i-1] + dp[i-1][j-weights[i-1]], dp[i-1][j]);
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][maxWeight];
}

int main(int argc, char const *argv[])
{
	int n;
	int w;
	cin >> n;
	int *weights = new int[n];
	int *values = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> weights[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> values[i];
	}
	cin >> w;
	cout << knapsack(weights, values, n, w);
	return 0;
}