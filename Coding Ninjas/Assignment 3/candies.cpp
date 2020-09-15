#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool remCandies(long input[], long ans, int pos, int n, long k)
{
	int count = 0;
	long num;
	int i;
	for(i = pos; i < n; i++)
	{
		num = input[i];
		while(num >= ans)
		{
			count++;
			num -= ans;
		}
		if(count == k)
			break;
	}
	if(i != n)
		return true;
	if(count > k)
		return true;
		
	return false;
}

bool isPossible(long input[], int index, int n, long k)
{
	int count = 1;
	long num;
	for(int i = index+1; i < n; i++)
	{
		num = input[i];
		while(num >= input[index])
		{
			count++;
			num -= input[index];
		}
		if(count >= k)
			return true;
	}
	
	return false;
}	

int candies(long input[], int n, long k)
{
	int start = 0;
	int end = n-1;
	int pos = -1;
	sort(input, input+n);
	
	while(start <= end)
	{
		int mid = (start+end)/2;
		if(isPossible(input, mid, n, k))
		{
			pos = mid;
			start = mid+1;
		}
		else
		{
			end = mid-1;
		}
	}
	
	long ans;
	if(pos < 0)
	{
		ans = 1;
	}
	else
	{
		ans = input[pos];
	}
	
	bool flag = 0;
	while(remCandies(input, ans, pos+1, n, k))
	{
		flag = 1;
		ans++;
	}
	if(flag == 1)
		return ans-1;
	else
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
