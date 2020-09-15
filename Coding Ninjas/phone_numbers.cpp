#include <bits/stdc++.h>

using namespace std;

int minCost(int cost[], int d, int sum)
{
	if (d == 0)
	{
		return cost[0];
	}
	if (d == 1)
	{
		return cost[1];
	}
	if (sum % 10 == d)
	{
		return 0;
	}

	int minimum = INT_MAX;
	for (int i = 1; i < d; ++i)
	{
		minimum = min(minimum, cost[i] + minCost(cost, d-i, sum + i));
	}

	minimum = min(minimum, cost[d]);

	return minimum;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int cost[9];
		for (int i = 0; i < 9; ++i)
		{
			cin >> cost[i];
		}
		int l;
		cin >> l;
		string s;
		cin >> s;
		int *calc = new int[l]();
		for (int i = 0; i < l; ++i)
		{
			if (calc[i] == 0)
			{
				calc[i] = minCost(cost, s[i]-'0', 0);
			}
		}

		int sum = 0;
		for (int i = 0; i < l; ++i)
		{
			sum += calc[i];
		}
		cout << sum << endl;
	}
	return 0;
}