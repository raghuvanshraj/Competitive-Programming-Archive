#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	bool *sieve = new bool[n+1]();
	for (int i = 0; i <= n; ++i)
	{
		sieve[i] = true;
	}

	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (sieve[i])
		{
			for (int j = i*i; j <= n; j += i)
			{
				sieve[j] = false;
			}
		}
	}

	int count = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (sieve[i])
		{
			count++;
		}
	}
	cout << count;
	return 0;
}