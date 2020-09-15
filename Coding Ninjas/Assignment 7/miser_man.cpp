#include <bits/stdc++.h>

using namespace std;

int min(int x, int y, int z)
{
	return min(min(x,y), z);
}

int miserMan(int **fare, int n, int m)
{
	int dp[n+1][m+1];
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < m+1; ++j)
		{
			if (i == 0 or j == 0)
			{
				dp[i][j] = 0;
				continue;
			}

			if (j == 1)
			{
				dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + fare[i-1][j-1];
			}
			else if (j == m)
			{
				dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + fare[i-1][j-1];
			}
			else
			{
				dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]) + fare[i-1][j-1];
			}
		}
	}

	int minCost = INT_MAX;
	for (int i = 1; i < m+1; ++i)
	{
		minCost = min(minCost, dp[n][i]);
	}

	return minCost;
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	int **fare = new int*[n];
	for (int i = 0; i < n; ++i)
	{
		fare[i] = new int[m];
		for (int j = 0; j < m; ++j)
		{
			cin >> fare[i][j];
		}
	}
	cout << miserMan(fare,n,m);
	return 0;
}