#include <bits/stdc++.h>

using namespace std;

long farida(long *input, int n)
{
	long *output = new long[n]();
	output[0] = input[0];
	output[1] = max(input[0], input[1]);

	for (int i = 2; i < n; ++i)
	{
		output[i] = max(output[i-1], output[i-2] + input[i]);
	}

	return output[n-1];
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		long *input = new long[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> input[i];
		}

		cout << "Case " << i+1 << ": " << farida(input,n) << endl;
	}
	return 0;
}