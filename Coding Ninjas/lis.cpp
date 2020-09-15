#include <bits/stdc++.h>

using namespace std;

int lis(int *arr, int n)
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
			if (arr[j] > arr[i] and lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
			}
		}
	}

	int max = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		max = (max < lis[i]) ? lis[i] : max;
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

	cout << lis(arr,n);

	return 0;
}