#include <bits/stdc++.h>

using namespace std;

long long pussyCat(long long **arr, int n, int m)
{
	long long **dp = new long long*[n+1]();
	for (int i = 0; i < n+1; ++i)
	{
		dp[i] = new long long[m+1]();
	}

	for (int i = 1; i < n+1; ++i)
	{
		for (int j = 1; j < m+1; ++j)
		{
			int max = dp[i-1][j];
			int start = 1;
			int end = (j > arr[i-1][0]) ? arr[i-1][0] : j;
			while (end != arr[i-1][0]+1) 
			{
				int sum = 0;
				for (int k = start, c = 1; k < end+1; ++k, ++c)
				{
					sum += arr[i-1][k];
					if (max < sum + dp[i-1][j-c])
					{
						max = sum + dp[i-1][j-c];
					}
				}

				for (int k = start, c = 1; k < end; ++k, ++c)
				{
					sum -= arr[i-1][k];
					if (max < sum + dp[i-1][j-(arr[i-1][0]-c)])
					{
						max = sum + dp[i-1][j-(arr[i-1][0]-c)];
					}
				}

				start++;
				end++;
			}

			dp[i][j] = max;
		}
	}

	return dp[n][m];
}

int main(int argc, char const *argv[])
{
	long long n,m;
	cin >> n >> m;
	long long **arr = new long long*[n]();
	for (long long i = 0; i < n; ++i)
	{
		long long size;
		cin >> size;
		arr[i] = new long long[size+1]();
		arr[i][0] = size;
		for (long long j = 1; j < size+1; ++j)
		{
			cin >> arr[i][j];
		}
	}

	cout << pussyCat(arr, n, m);
	return 0;
}