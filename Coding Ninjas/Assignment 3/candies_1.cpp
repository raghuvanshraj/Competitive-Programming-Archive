#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isPossible(long input[], long ans, int n, long k)
{
	int count = 0;
	long num;
	for(int i = 0; i < n; i++)
	{
		num = input[i];
		while(num >= ans)
		{
			count++;
			num -= ans;
		}
		if(count >= k)
			return true;
	}
	
	return false;
}	

long candies(long input[], int n, long k)
{
	sort(input, input+n);
	long start = 0;
	long end = input[n-1];
	long mid = (start+end)/2;
	long ans;
	while(start <= end)
	{
		mid = (start+end)/2;
		if(isPossible(input, mid, n, k))
		{
			ans = mid;
			start = mid+1;
		}
		else
		{
			end = mid-1;
		}
	}
	
	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		long *input = new long[n];
		for(int i = 0; i < n; i++)
			cin >> input[i];
			
		cout << candies(input, n, k) << endl;
	}
	
	return 0;
}

