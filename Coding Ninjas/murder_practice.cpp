#include <bits/stdc++.h>

using namespace std;

long merge(int *arr, int l, int m, int r)
{
	int eltL = m-l+1;
	int eltR = r-m;
	int *tempL = new int[eltL];
	int *tempR = new int[eltR];
	for (int i = 0; i < eltL; ++i)
	{
		tempL[i] = arr[l+i];
	}
	for (int i = 0; i < eltR; ++i)
	{
		tempR[i] = arr[m+1+i];
	}

	int i = 0;
	int j = 0;
	int k = l;
	long sum = 0;
	while (i < eltL and j < eltR)
	{
		if (tempL[i] >= tempR[j])
		{
			arr[k] = tempL[i];
			i++;
			k++;
		}
		else
		{
			arr[k] = tempR[j];
			for (int v = i; v < eltL; ++v)
			{
				sum += tempL[v];
			}
			j++;
			k++;
		}
	}

	while (i < eltL)
	{
		arr[k] = tempL[i];
		i++;
		k++;
	}
	while (j < eltR)
	{
		arr[k] = tempR[j];
		j++;
		k++;
	}

	return sum;
}

long mergeSort(int *arr, int l, int r)
{
	long sum = 0;
	if (l < r)
	{
		int m = (l + r) / 2;
		sum += mergeSort(arr,l,m);
		sum += mergeSort(arr,m+1,r);

		sum += merge(arr,l,m,r);
	}

	return sum;
}

long solve(int *arr, int n)
{
	return mergeSort(arr, 0, n-1);
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int *arr = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		cout << solve(arr,n) << endl;
	}
	
	return 0;
}