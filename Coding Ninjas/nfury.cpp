#include <bits/stdc++.h>

using namespace std;

int optimal[1001];

void nfury()
{
	int dp[33][1001];
	dp[0][0] = 0;

	memset(optimal, 100, 1001*sizeof(int));
	for(int i = 1; i < 33; i++)
	{
		for(int j = 1; j < 1001; j++)
		{
			if(i == 1)
			{
				dp[i][j] = j;
			}
			else if(pow(i,2) > j)
			{
				dp[i][j] = dp[i-1][j];
			}
			else if(pow(i,2) < j)
			{
				dp[i][j] = dp[i-1][j % int(pow(i,2))] + (j/int(pow(i,2)));
			}
			else
			{
				dp[i][j] = 1;
			}

			optimal[j] = min(optimal[j],dp[i][j]);
			dp[i][j] = optimal[j];
		}
	}
}

int main()
{
	nfury();
	int t;
	cin >> t;
	while(t--)
	{
		int a;
		cin >> a;

		cout << optimal[a] << endl;
	}

	return 0;
}