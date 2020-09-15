#include <iostream>
#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

vector<long> primes;
unordered_map<long,long> primeK;

void createSieve()
{
	bool *sieve = new bool[MAX];
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

long maxPower(long num, long prime)
{
	long power = 0;
	while(num%prime == 0)
	{
		power++;
		num /= prime;
	}

	return power;
}

unordered_map<long,long> primeFactorize(long num)
{
	unordered_map<long,long> numPrime;
	for(long prime : primes)
	{
		if(prime > num)
			break;

		if(num%prime == 0)
		{
			numPrime[prime] = maxPower(num, prime);
		}
	}

	return numPrime;
}

bool isDivisible(vector<long> input, long start, long end, long k)
{
	unordered_map<long,long> masterPrime;
	for(long i = start; i <= end; i++)
	{
		unordered_map<long,long> eltPrime = primeFactorize(input[i]);
		for(pair<long,long> factor : eltPrime)
		{
			masterPrime[factor.first] += factor.second;
		}
	}
	for(pair<long,long> factor : primeK)
	{
		if(masterPrime[factor.first] < primeK[factor.first])
			return false;
	}

	return true;
}

long cardGame(vector<long> input, long n, long k)
{
	long i = 0;
	long j = 0;
	long ans = 0;
	while(j < n)
	{
		if(isDivisible(input, i, j, k))
		{
			i++;
			ans += n-j;
			if(i > j)
				j++;
		}
		else
		{
			j++;
		}
	}

	return ans;
}

int main()
{
	long n,k;
	createSieve();
	cin >> n >> k;
	vector<long> input(n);
	primeK = primeFactorize(k);
	for(long i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	cout << cardGame(input, n, k);
}