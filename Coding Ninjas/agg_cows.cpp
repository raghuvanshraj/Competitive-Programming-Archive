#include <iostream>
#include <algorithm>

using namespace std;

bool check(long long positions[], int n, int c, int distance)
{
	long long last = positions[0];
	int count = 1;
	
	for(int i = 0; i < n; i++)
	{
		if(positions[i]-last >= distance)
		{
			last = positions[i];
			count++;
		}
		
		if(count == c)
			return true;
	}
	
	return false;
}
	

int main()
{	
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		int c;
		int ans = -1;
		cin >> n >> c;
		
		long long positions[n];
		for(int i = 0; i < n; i++)
			cin >> positions[i];
		
		sort(positions, positions+n);
		long long start = 0;
		long long end = positions[n-1]-positions[0];
			
		while(start <= end)
		{
			long long mid = start + (end-start)/2;
			
			if(check(positions, n, c, mid))
			{
				ans = mid;
				start = mid+1;
			}
			else
			{
				end = mid-1;
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
