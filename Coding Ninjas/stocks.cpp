#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	long n,m,a,b;
	cin >> n >> m >> a >> b;
	long *c = new long[n]();
	long *x = new long[n]();
	long const1 = long(pow(2,32));
	long const2 = long(pow(2,8));
	long buyPrice = 0;
	long sellPrice = 0;
	long totalProfit = 0;
	bool selling = true;
	for (int i = 1; i < n; ++i)
	{
		x[i] = ((x[i-1] % m)*a + b) % const1;
		c[i] = x[i] / const2;
		cout << x[i] << " " << c[i] << endl;
		if (selling)
		{
			if (c[i] >= c[i-1])
			{
				sellPrice = c[i];
				if (i == n-1)
				{
					totalProfit += c[i] - buyPrice;
					break;
				}
			}
			else
			{
				totalProfit += sellPrice - buyPrice;
				selling = false;
			}
		}
		else
		{
			if (c[i] <= c[i-1])
			{
				buyPrice = c[i];
			}
			else
			{
				selling = true;
			}
		}
	}

	cout << totalProfit;
	return 0;
}