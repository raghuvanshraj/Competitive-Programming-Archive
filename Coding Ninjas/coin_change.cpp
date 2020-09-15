#include <bits/stdc++.h>

using namespace std;

long countWaysToMakeChange(int denominations[], int numDenominations, int value)
{
	long table[value+1][numDenominations];
    memset(table, 0, sizeof(table));
	for(int i = 0; i < numDenominations; i++)
	{
		table[0][i] = 1;
	}

	for(int i = 1; i < value+1; i++)
	{
		for(int j = 0; j < numDenominations; j++)
		{
			long x = (i-denominations[j] >= 0) ? table[i-denominations[j]][j] : 0;
			long y = (j >= 1) ? table[i][j-1] : 0;

			table[i][j] = x+y;
		}
	}

	return table[value][numDenominations-1];
}

int main()
{
	int n,m;
	cin >> n >> m;
	int *denominations = new int[m];
	for(int i = 0; i < m; i++)
	{
		cin >> denominations[i];
	}
	
	cout << countWaysToMakeChange(denominations,m,n);
}