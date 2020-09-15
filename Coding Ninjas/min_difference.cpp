#include <bits/stdc++.h>

using namespace std;

int minAbsoluteDiff(int arr[], int n)
{
	sort(arr, arr+n);
	int *diff = new int[n-1];
	for (int i = 0; i < n-1; ++i)
	{
		diff[i] = abs(arr[i+1] - arr[i]);
	}

	sort(diff, diff+n-1);
	return diff[0];
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
	
	cout << minAbsoluteDiff(arr, n);
	return 0;
}