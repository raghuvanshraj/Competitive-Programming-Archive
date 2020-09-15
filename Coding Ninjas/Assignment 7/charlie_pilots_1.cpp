#include <bits/stdc++.h>

using namespace std;

struct Pilot
{
	int captain;
	int assistant;
};

int minimumSalary(Pilot *pilots, int n, int diff, int **dp)
{
	if (dp[n][diff] > -1)
	{
		return dp[n][diff];
	}
	if (n == 0)
	{
		dp[n][diff] = 0;
		return 0;
	}

	if (diff == 0)
	{
		dp[n][diff] = pilots[0].assistant + minimumSalary(pilots+1, n-1, diff+1, dp);
		return dp[n][diff];
	}
	else if (diff == n)
	{
		dp[n][diff] = pilots[0].captain + minimumSalary(pilots+1, n-1, diff-1, dp);
		return dp[n][diff];
	}

	dp[n][diff] = min(pilots[0].assistant + minimumSalary(pilots+1, n-1, diff+1, dp), 
			          pilots[0].captain + minimumSalary(pilots+1, n-1, diff-1, dp));

	return dp[n][diff];
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	Pilot *pilots = new Pilot[n];
	int **dp = new int*[n+1]();
	for (int i = 0; i < n+1; ++i)
	{
		dp[i] = new int[n/2 + 1]();
		for (int j = 0; j < n/2 + 1; ++j)
		{
			dp[i][j] = -1;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> pilots[i].captain >> pilots[i].assistant;
	}
	cout << minimumSalary(pilots, n, 0, dp);
	return 0;
}