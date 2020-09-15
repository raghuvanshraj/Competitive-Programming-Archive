#include <bits/stdc++.h>

using namespace std;

int* longestIncreasing(int* arr, int size) 
{
	int *lis = new int[size];

	for(int i = 0; i < size; i++)
		lis[i] = 1;

	for(int i = 1; i < size; i++) 
	{
		for(int j = 0; j < i; j++) 
		{
			if(arr[i] > arr[j] and lis[j]+1 > lis[i])
				lis[i] = lis[j]+1;
		}
	}

	return lis;
}

int* longestDecreasing(int* arr, int size) 
{
	int *lds = new int[size];

	for(int i = 0; i < size; i++)
		lds[i] = 1;

	for(int i = size-2; i >= 0; i--) 
	{
		for(int j = size-1; j > i; j--) 
		{
			if(arr[i] > arr[j] and lds[j]+1 > lds[i])
				lds[i] = lds[j]+1;
		}
	}

	return lds;
}

int longestBitonicSubarray(int *input, int n)
{
	int *lis = new int[n];
	lis = longestIncreasing(input,n);
	int *lds = new int[n];
	lds = longestDecreasing(input,n);

	int max = 0;
	for(int i = 0; i < n; i++)
	{
		if(lis[i]+lds[i]-1 > max)
			max = lis[i]+lds[i]-1;
	}

	return max;
}

int main()
{
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++)
		cin >> input[i];

	cout << longestBitonicSubarray(input, n);

	return 0;
}