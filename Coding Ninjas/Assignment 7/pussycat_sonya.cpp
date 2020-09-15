#include <bits/stdc++.h>

using namespace std;

long long pussyCat(long long **arr, long long n, long long m, long long pos)
{
	if (m < 0)
	{
		return -1;
	}
	if (n == 0)
	{
		return 0;
	}

	long long ans = pussyCat(arr, n-1, m, pos+1);
	long long max;
	if (ans < 0)
	{
		max = 0;
	}
	else
	{
		max = ans;
	}
	long long sum = 0;
	for (long long i = 1; i < arr[pos][0]+1; ++i)
	{
		sum += arr[pos][i];
		long long ans = pussyCat(arr, n-1, m-i, pos+1);
		if (ans < 0)
		{
			continue;
		}
		long long curr = sum + ans;
		if (max < curr)
		{
			max = curr;
		}
	}

	for (long long i = 1; i < arr[pos][0]; ++i)
	{
		sum -= arr[pos][i];
		long long ans = pussyCat(arr, n-1, m-(arr[pos][0]-i), pos+1);
		if (ans < 0)
		{
			continue;
		}
		long long curr = sum + ans;
		if (max < curr)
		{
			max = curr;
		}
	}

	if (max < 0)
	{
		return 0;
	}
	return max;
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

	cout << pussyCat(arr, n, m, 0);
	return 0;
}