#include <bits/stdc++.h>

using namespace std;

bool isPossible(long *input, int n, int k, long mid)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		long curr = input[i];
		while (curr >= mid)
		{
			curr -= mid;
			count++;
		}
		if (count >= k)
		{
			return true;
		}
	}

	return false;
}

long candies(long *input, int n, int k)
{
	sort(input, input+n);
	long l = 0;
	long r = input[n-1];
	long mid = (l + r) / 2;
	long ans;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (isPossible(input,n,k,mid))
		{
			ans = mid;
			l = mid+1;
		}
		else
		{
			r = mid-1;
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
		{
			cin >> input[i];
		}
			
		cout << candies(input, n, k) << endl;
	}
	
	return 0;
}