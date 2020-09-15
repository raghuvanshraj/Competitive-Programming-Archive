#include <iostream>
#include <bits/stdc++.h>
#define MAX 200

using namespace std;

vector<int> primes;

void createSieve()
{
	bool sieve[MAX];
	for(int i = 0; i < MAX; i++)
		sieve[i] = true;

	for(int i = 2; i < sqrt(MAX); i++)
	{
		if(sieve[i])
		{
			int temp = i;
			for(int j = pow(i,2); j < MAX; j = i*(++temp))
				sieve[j] = false;
		}
	}

	for(int i = 2; i < MAX; i++)
	{
		if(sieve[i])
			primes.push_back(i);
	}
}

int main()
{
	createSieve();
	for(int i = 0; i < primes.size(); i++)
		cout << primes[i] << " ";

	return 0;
}