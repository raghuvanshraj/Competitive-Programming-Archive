#include <bits/stdc++.h>

using namespace std;

int maxProfit(int *prices, int n, int k, int active, int ***dp)
{
	if (dp[n][k][active] > -1)
	{
		return dp[n][k][active];
	}
	
	if (n == 0 or k == 0)
	{
		dp[n][k][active] = 0;
		return 0;
	}

	int ans1 = maxProfit(prices+1, n-1, k, active, dp);
	int ans2;
	if (active == 0)
	{
		ans2 = -prices[0] + maxProfit(prices+1, n-1, k, 1, dp);
	}
	else
	{
		ans2 = prices[0] + maxProfit(prices+1, n-1, k-1, 0, dp);
	}

	dp[n][k][active] = max(ans1, ans2);

	return dp[n][k][active];
}

int main(int argc, char const *argv[])
{
	int q;
	cin >> q;
	while (q--)
	{
		int n,k;
		cin >> k >> n;
		int *prices = new int[n];
		int ***dp = new int**[n+1];
		for (int i = 0; i < n+1; ++i)
		{
			dp[i] = new int*[k+1]();
			for (int j = 0; j < k+1; ++j)
			{
				dp[i][j] = new int[2]();
				for (int l = 0; l < 2; ++l)
				{
					dp[i][j][l] = -1;
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> prices[i];
		}

		cout << maxProfit(prices, n, k, 0, dp) << endl;
	}
	return 0;
}