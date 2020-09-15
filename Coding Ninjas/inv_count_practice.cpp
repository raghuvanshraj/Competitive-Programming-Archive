#include <bits/stdc++.h>

using namespace std;

long long merge(int arr[], int l, int m, int r)
{
	int invCount = 0;
	int eltLeft = m-l+1;
	int eltRight = r-m;

	int *tempL = new int[eltLeft];
	int *tempR = new int[eltRight];

	for (int i = 0; i < eltLeft; ++i)
	{
		tempL[i] = arr[i+l];
	}
	for (int i = 0; i < eltRight; ++i)
	{
		tempR[i] = arr[m+i+1];
	}

	int i = 0;
	int j = 0;
	int k = l;
	while (i < eltLeft and j < eltRight)
	{
		if (tempL[i] <= tempR[j])
		{
			arr[k] = tempL[i];
			i++;
		}
		else
		{
			arr[k] = tempR[j];
			invCount += m+1 - (i+l);
			j++;
		}
		k++;
	}

	while (i < eltLeft)
	{
		arr[k] = tempL[i];
		k++;
		i++;
	}
	while(j < eltRight)
	{
		arr[k] = tempR[j];
		j++;
		k++;
	}

	return invCount;
}

long long mergeSort(int arr[], int l, int r)
{
	long long invCount = 0;
	if (l < r)
	{
		int m = (l + r) / 2;
		invCount += mergeSort(arr, l, m);
		invCount += mergeSort(arr, m+1, r);

		invCount += merge(arr, l, m, r);
	}

	return invCount;
}

long long solve(int arr[], int n)
{
	return mergeSort(arr, 0, n-1);
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

	cout << solve(arr,n);

	return 0;
}