#include <bits/stdc++.h>

using namespace std;

int coinChange(int *den, int n, int v)
{
	int table[v+1][n];

	memset(table, 0, (v+1) * (n+1) * sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		table[0][i] = 1;
	}

	for (int i = 1; i < v+1; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int x = (i - den[j] >= 0) ? table[i - den[j]][j] : 0;
			int y = (j >= 1) ? table[i][j-1] : 0;

			table[i][j] = x+y;
		}
	}

	return table[v][n-1];
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *den = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> den[i];
	}
	int v;
	cin >> v;

	cout << coinChange(den,n,v);

	return 0;
}