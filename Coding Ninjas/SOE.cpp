#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;

vector<int> primes;

void createSieve()
{
	bool *sieve = new bool[MAX];
	for(int i = 0; i < MAX; i++)
		sieve[i] = true;

	for(int i = 2; i < sqrt(MAX); i++)
	{
		if(sieve[i] == true)
		{
			for(int j = pow(i,2); j < MAX; j += i)
			{
				sieve[j] = false;
			}
		}
	}

	for(int i = 2; i < MAX; i++)
	{
		if(sieve[i])
		{
			primes.push_back(i);
		}
	}
}

int main()
{
	createSieve();
	for(int i = 0; i < primes.size(); i++)
		cout << primes[i] <<  " ";

	return 0;
}