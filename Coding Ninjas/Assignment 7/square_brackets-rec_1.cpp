#include <bits/stdc++.h>

using namespace std;

int countProper(bool opening[], int size, int o, int c, int pos, int **dp)
{
	if (size == 0)
	{
		return (o == c) ? 1 : 0;
	}
	if (dp[size][o] > -1)
	{
		return dp[size][o];
	}

	if (o == c)
	{
		dp[size][o] = countProper(opening, size-1, o+1, c, pos+1, dp);
		return dp[size][o];
	}
	else if (o-c == size)
	{
		if (opening[pos])
		{
			return 0;
		}
		dp[size][o] = countProper(opening, size-1, o, c+1, pos+1, dp);
		return dp[size][o];
	}
	else
	{
		if (opening[pos])
		{
			dp[size][o] = countProper(opening, size-1, o+1, c, pos+1, dp);
			return dp[size][o];
		}
		dp[size][o] = countProper(opening, size-1, o+1, c, pos+1, dp) +
			   		  countProper(opening, size-1, o, c+1, pos+1, dp);
		return dp[size][o];
	}
}

int main(int argc, char const *argv[])
{
	int d;
	cin >> d;
	while (d--)
	{
		int n,k;
		cin >> n >> k;
		bool opening[2*n];
		memset(opening, false, 2*n);
		for (int i = 0; i < k; ++i)
		{
			int index;
			cin >> index;
			opening[index-1] = true;
		}
		int **dp = new int*[2*n + 1]();
		for (int i = 0; i < 2*n + 1; ++i)
		{
			dp[i] = new int[2*n + 1]();
			for (int j = 0; j < 2*n + 1; ++j)
			{
				dp[i][j] = -1;
			}
		}
		cout << countProper(opening, 2*n, 0, 0, 0, dp) << endl;
	}
	return 0;
}