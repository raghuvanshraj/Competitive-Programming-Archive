#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	int *coins = new int[n+1];
	int *left = new int[n+1];
	int *right = new int[n+1];
	for (int i = 0; i < m; i++)
	{
		int l,r;
		cin >> l >> r;
		left[l]++;
		right[r]++;
	}
	coins[0] = 0;
	coins[1] = left[1];
	for (int i = 2; i < n+1; ++i)
	{
		coins[i] = left[i] - right[i-1] + coins[i-1];
	}
	int *dp = new int[m+1];
	dp[0] = 0;
	for(int i = 1; i < n+1; i++)
	{
		dp[coins[i]]++;
	}
	int *atleast = new int[m+1];
	atleast[m] = dp[m];
	for(int i = m-1; i >= 0; i--)
	{
		atleast[i] = dp[i] +atleast[i+1];
	}
	int q;
	cin >> q;
	while(q--)
	{
		int i;
		cin >> i;
		if(i > m)
		{
			cout << "0" << endl;
		}
		else
		{
			cout << atleast[i] << endl;
		}
	}

	return 0;
}