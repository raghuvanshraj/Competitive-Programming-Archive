#include <bits/stdc++.h>

using namespace std;

struct Pilot
{
	int captain;
	int assistant;
};

int dp[10001][5001];

int minimumSalary(Pilot *pilots, int n, int diff)
{
	if (n == 0)
	{
		dp[n][diff] = 0;
		return 0;
	}

	if (diff == 0)
	{
		if (dp[n-1][diff+1] > -1)
		{
			dp[n][diff] = pilots[0].assistant + dp[n-1][diff+1];
			return dp[n][diff];
		}
		return pilots[0].assistant + minimumSalary(pilots+1, n-1, diff+1);
	}
	else if (diff == n)
	{

		if (dp[n-1][diff-1] > -1)
		{
			dp[n][diff] = pilots[0].captain + dp[n-1][diff-1];
			return dp[n][diff];
		}
		return pilots[0].captain + minimumSalary(pilots+1, n-1, diff-1);
	}

	if (dp[n-1][diff+1] > -1 and dp[n-1][diff-1] > -1)
	{
		dp[n][diff] = min(pilots[0].assistant + dp[n-1][diff+1], pilots[0].captain + dp[n-1][diff-1]);
		return dp[n][diff];
	}
	return min(pilots[0].assistant + minimumSalary(pilots+1, n-1, diff+1), 
			   pilots[0].captain + minimumSalary(pilots+1, n-1, diff-1));
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	Pilot *pilots = new Pilot[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> pilots[i].captain >> pilots[i].assistant;
	}
	int dp[n][n/2 + 1];
	memset(dp, -1, sizeof(int) * (10001) * (5001));
	cout << minimumSalary(pilots, n, 0);
	return 0;
}