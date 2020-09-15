#include <bits/stdc++.h>

using namespace std;

int dp[1000];

int calcMin(int *cost, int currTarget, int sum, int currCost)
{
	if (sum % 10 == currTarget)
	{
		return currCost;
	}

	int min = INT_MAX;
	for (int i = 0; i < 9; ++i)
	{
		int tempCost = calcMin(cost, currTarget, (sum + i) % 10, currCost + cost[i]);
		min = (min > tempCost) ? tempCost : min;
	}

	return min;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof(int) * 1000);
		int cost[10];
		for (int i = 0; i < 10; ++i)
		{
			cin >> cost[i];
		}
		int n;
		cin >> n;
		int *target = new int[n];
		string targetString;
		cin >> targetString;
		for (int i = 0; i < n; ++i)
		{
			target[i] = targetString[i] - '0';
		}

		
	}
	return 0;
}