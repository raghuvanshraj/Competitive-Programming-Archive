#include <bits/stdc++.h>

using namespace std;

int* longestInc(int *arr, int n)
{
	int *lis = new int[n];
	for (int i = 0; i < n; ++i)
	{
		lis[i] = 1;
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (arr[i] > arr[j] and lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
			}
		}
	}

	return lis;
}

int* longestDec(int *arr, int n)
{
	int *lds = new int[n];
	for (int i = 0; i < n; ++i)
	{
		lds[i] = 1;
	}

	for (int i = n-2; i >= 0; --i)
	{
		for (int j = n-1; j > i; --j)
		{
			if (arr[i] > arr[j] and lds[i] < lds[j] + 1)
			{
				lds[i] = lds[j] + 1;
			}
		}
	}

	return lds;
}

int longestBitonicSubarray(int *input, int n)
{
	int *lis = longestInc(input, n);
	int *lds = longestDec(input, n);

	int max = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		max = (max < lis[i] + lds[i] -1) ? lis[i] + lds[i] -1 : max;
	}

	return max;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << longestBitonicSubarray(arr,n);
	return 0;
}