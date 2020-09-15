#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *dim = new int[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		cin >> dim[i];
	}

	int **dp = new int*[n]();
	for (int i = 0; i < n; ++i)
	{
		dp[i] = new int[n+1]();
		// for (int j = 0; j < n+1; ++j)
		// {
		// 	dp[i][j] = 1;
		// }
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n+1; ++j)
		{
			int min = INT_MAX;
			for (int k = i+1; k < j; ++k)
			{
				int curr = dp[i][k] + dp[k][j] + (dim[i] * dim[k] * dim[j]);
				min = (min > curr) ? curr : min;
			}

			dp[i][j] = (min == INT_MAX) ? 0 : min;
		}
	}

	cout << dp[0][n];
	return 0;
}