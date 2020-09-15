#include <bits/stdc++.h>
#define MAXN 16

using namespace std;
typedef long long ll;

int countSet(int mask, int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (mask & (1 << i))
		{
			count++;
		}
	}

	return count;
}

ll solve(int like[][MAXN], int n)
{
	int *dp = new int[int(pow(2,n))]();
	dp[0] = 1;
	for (int mask = 0; mask < pow(2,n); ++mask)
	{
		int i = countSet(mask, n);
		for (int j = 0; j < n; ++j)
		{
			if (((mask & (1 << j)) == 0) and like[i][j] == 1)
			{
				dp[mask | (1 << j)] += dp[mask];
			}
		}
	}

	return dp[int(pow(2,n))-1];
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int like [MAXN][MAXN];
	memset(like, 0, MAXN * MAXN * sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> like[i][j];
		}
	}

	cout << solve(like, n);

	return 0;
}