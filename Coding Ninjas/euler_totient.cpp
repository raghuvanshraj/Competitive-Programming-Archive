#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long double ld;

vector<ull> primes;

void createSieve(ull n)
{
	bool *sieve = new bool[n];
	for(ull i = 0; i <= n; i++)
	{
		sieve[i] = true;
	}

	for(ull i = 2; i <= sqrt(n); i++)
	{
		if(sieve[i])
		{
			for(ull j = pow(i,2); j <= n; j += i)
			{
				sieve[j] = false;
			}
		}
	}

	for(ull i = 2; i <= n; i++)
	{
		if(sieve[i])
		{
			primes.push_back(i);
		}
	}
}

vector<ull> primeFactors(ull n)
{
	createSieve(n);
	vector<ull> factors;
	for(ull prime : primes)
	{
		if(prime > n)
			return factors;

		if(n%prime == 0)
			factors.push_back(prime);
	}

	return factors;
}

ull eulerTotient(ull n)
{
	ld mult = 1;
	vector<ull> factors = primeFactors(n);
	for(ull factor : factors)
	{
		mult *= ld(factor-1)/ld(factor);
	}

	return n*mult;
}

int main()
{
	ull n;
	cin >> n;
	cout << eulerTotient(n);

	return 0;
}