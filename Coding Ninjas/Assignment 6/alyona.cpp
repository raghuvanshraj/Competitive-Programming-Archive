#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	int **table = new int*[n];
	int **dp = new int*[n];
	for(int i = 0; i < n; i++)
	{
		table[i] = new int[m];
		dp[i] = new int[m];
		for(int j = 0; j < m; j++)
		{
			cin >> table[i][j];
			if(i == 0)
			{
				dp[i][j] = i;
				continue;
			}
			if(table[i][j] >= table[i-1][j])
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = i;
			}
		}
	}

	int q;
	cin >> q;
	while(q--)
	{
		int i,j;
		bool flag = false;
		cin >> i >> j;
		for(int k = 0; k < m; k++)
		{
			if(dp[j-1][k] <= i-1)
			{
				cout << "Yes\n";
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			cout << "No\n";
		}
	}

	return 0;
}