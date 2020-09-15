#include <bits/stdc++.h>

using namespace std;

int kadane(int *input, int size)
{
	int best = INT_MIN;
	int curr = 0;
	for(int i = 0; i < size; i++)
	{
		curr += input[i];
		if(best < curr)
		{
			best = curr;
		}
		if(curr < 0)
		{
			curr = 0;
		}
	}
	
	return best;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int *input = new int[n];
		for(int i = 0; i < n; i++)
		{
			cin >> input[i];
		}

		cout << kadane(input,n) << endl;
	}
}