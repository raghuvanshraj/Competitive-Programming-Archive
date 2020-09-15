#include <bits/stdc++.h>

using namespace std;

struct Cycle
{
	int buy;
	int sell;
};

int main(int argc, char const *argv[])
{
	long n,m,a,b;
	cin >> n >> m >> a >> b;
	long *x = new long[n]();
	long *c = new long[n]();
	Cycle *cycle = new Cycle[n]();
	long const1 = long(pow(2,32));
	long const2 = long(pow(2,8));
	for (int i = 1; i < n; ++i)
	{
		x[i] = ((x[i-1] % m)*a + b) % const1;
		c[i] = x[i] / const2;
	}

	int i = 1;
	int count = 0;
	while (i < n)
	{
		while ((i < n) and c[i] <= c[i-1])
		{
			i++;
		}
		if (i == n-1)
		{
			break;
		}

		cycle[count].buy = i-1;

		while ((i < n) and c[i] >= c[i-1])
		{
			i++;
		}

		cycle[count].sell = i-1;
		count++;
	}

	long totalProfit = 0;
	for (int i = 0; i < count; ++i)
	{
		totalProfit += c[cycle[i].sell]-c[cycle[i].buy];
	}

	cout << totalProfit;
	return 0;
}