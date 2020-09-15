#include <bits/stdc++.h>

using namespace std;

long farida(long *input, long n)
{
	long *output = new long[n];
	for(long i = 0; i < n; i++)
	{
		if(i == 0)
		{
			output[i] = input[i];
			continue;
		}

		if(i == 1)
		{
			output[i] = max(input[0],input[1]);
			continue;
		}

		output[i] = max(output[i-2]+input[i],output[i-1]);
	}

	long max = 0;
	for(long i = 0; i < n; i++)
	{
		if(max < output[i])
			max = output[i];
	}

	return max;
}

int main()
{
	int t;
	cin >> t;
	for(int j = 1; j <= t; j++)
	{
		long n;
		cin >> n;
		long *input = new long[n];
		for(long i = 0; i < n; i++)
			cin >> input[i];

		cout << "Case " << j << ": " << farida(input,n) << endl;
	}

	return 0;
}