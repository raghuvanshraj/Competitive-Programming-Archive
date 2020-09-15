#include <bits/stdc++.h>

using namespace std;

struct Party
{
	int price;
	int fun;
};

void maxFun(Party *parties, int n, int budget)
{
	Party dp[budget+1];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i < n; ++i)
	{
		for (int j = budget; j >= parties[i].price; --j)
		{
			if (parties[i].fun + dp[j-parties[i].price].fun > dp[j].fun)
			{
				dp[j].price = parties[i].price + dp[j-parties[i].price].price;
				dp[j].fun = parties[i].fun + dp[j-parties[i].price].fun;
			}
		}
	}

	int maxFun = dp[budget].fun;
	int minPrice = INT_MAX;
	for (int i = 0; i < budget+1; ++i)
	{
		if (dp[i].fun == maxFun)
		{
			if (dp[i].price < minPrice)
			{
				minPrice = dp[i].price;
			}
		}
	}

	cout << minPrice << " " << maxFun << endl;
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

		maxFun(parties,n,budget);
		// cout << final.price << " " << final.fun << endl;
	}

	return 0;
}