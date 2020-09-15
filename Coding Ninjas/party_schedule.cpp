#include <bits/stdc++.h>

using namespace std;

struct Party
{
	int price;
	int fun;
};

Party maxFun(Party *parties, int n, int budget)
{
	Party dp[n+1][budget+1];

	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < budget+1; ++j)
		{
			if (i == 0 or j == 0)
			{
				dp[i][j].price = 0;
				dp[i][j].fun = 0;
			}
			else if (parties[i-1].price <= j)
			{
				if (parties[i-1].fun + dp[i-1][j-parties[i-1].price].fun > dp[i-1][j].fun)
				{
					dp[i][j].price = parties[i-1].price + dp[i-1][j-parties[i-1].price].price;
					dp[i][j].fun = parties[i-1].fun + dp[i-1][j-parties[i-1].price].fun;
				}
				else
				{
					dp[i][j] = dp[i-1][j];
				}
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][budget];
}

int main(int argc, char const *argv[])
{
	while (true)
	{
		int budget, n;
		cin >> budget >> n;
		if (n == 0 and budget == 0)
		{
			break;
		}
		Party *parties = new Party[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> parties[i].price >> parties[i].fun;
		}

		Party final = maxFun(parties,n,budget);
		cout << final.price << " " << final.fun << endl;
	}

	return 0;
}