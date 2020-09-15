#include <bits/stdc++.h>

using namespace std;

int max(int x, int y, int z)
{
	return max(max(x,y), z);
}

int maxProfit(int *prices, int n, int k, bool active)
{
	if (n == 0 or k == 0)
	{
		return 0;
	}

	if (!active)
	{
		return max(-prices[0] + maxProfit(prices+1, n-1, k, true),
				   maxProfit(prices+1, n-1, k, active));
	}
	else
	{
		return max(prices[0] + maxProfit(prices+1, n-1, k-1, false), 
			   	   maxProfit(prices+1, n-1, k, active));
	}
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
		for (int i = 0; i < n; ++i)
		{
			cin >> prices[i];
		}

		cout << maxProfit(prices, n, k, false) << endl;
	}
	return 0;
}