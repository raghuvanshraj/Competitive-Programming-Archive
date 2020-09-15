#include <bits/stdc++.h>

using namespace std;

void matrixChain(int *dim, int start, int end, int **dp)
{
	if (end == start+1)
	{
		dp[start][end] = 0;
		return;
	}
	
  	int min = INT_MAX;
	for (int i = start+1; i < end; ++i)
	{
		if (dp[start][i] == -1)
		{
			matrixChain(dim, start, i, dp);
		}
		if (dp[i][end] == -1)
		{
			matrixChain(dim, i, end, dp);
		}

		int curr = dp[start][i] + dp[i][end] + (dim[start] * dim[i] * dim[end]);
      	min = (min > curr) ? curr : min;
	}
  	dp[start][end] = min;
}

int mcm(int *dim, int n)
{
	int **dp = new int*[n]();
	for (int i = 0; i < n; ++i)
	{
		dp[i] = new int[n+1]();
		for (int j = 0; j < n+1; ++j)
		{
			dp[i][j] = -1;
		}
	}

 	matrixChain(dim, 0, n, dp);
 	return dp[0][n];
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *dim = new int[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		cin >> dim[i];
	}

	cout << mcm(dim, n);

	return 0;
}