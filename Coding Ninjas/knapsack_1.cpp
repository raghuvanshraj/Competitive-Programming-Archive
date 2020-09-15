#include <bits/stdc++.h>

using namespace std;

int knapsack(int *weights, int *values, int n, int w)
{
	int *dp = new int[w+1];

	for (int i = 0; i < n; ++i)
	{
		for (int j = w; j >= weights[i]; --j)
		{
			dp[j] = max(dp[j], values[i] + dp[j-weights[i]]);
		}
	}

	return dp[w];
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