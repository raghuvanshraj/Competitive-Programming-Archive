#include <bits/stdc++.h>

using namespace std;

struct DP
{
	int cost = -1;
	int result = 1;
};

void potions(vector<int> colors, int start, int end, DP **dp)
{
	if (end == start+1)
	{
		dp[start][end].cost = 0;
		dp[start][end].result = colors[start];
		return;
	}
	
  	int minCost = INT_MAX;
  	int result;
	for (int i = start+1; i < end; ++i)
	{
		if (dp[start][i].cost == -1)
		{
			potions(colors, start, i, dp);
		}
		if (dp[i][end].cost == -1)
		{
			potions(colors, i, end, dp);
		}

		int curr = dp[start][i].cost + dp[i][end].cost + (dp[start][i].result * dp[i][end].result);
      	if (minCost > curr)
      	{
      		minCost = curr;
      		result = (dp[start][i].result + dp[i][end].result) % 100;
      	}
	}

  	dp[start][end].cost = minCost;
  	dp[start][end].result = result;
}

int solve(int n, vector<int> colors)
{
	DP **dp = new DP*[n]();
	for (int i = 0; i < n; ++i)
	{
		dp[i] = new DP[n+1]();
	}

	potions(colors, 0, n, dp);
	return dp[0][n].cost;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> colors;
	for (int i = 0; i < n; ++i)
	{
		int elt;
		cin >> elt;
		colors.push_back(elt);
	}

	cout << solve(n, colors);

	return 0;
}