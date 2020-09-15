#include <iostream>
#include <bits/stdc++.h>
#define MAX 100

using namespace std;

vector<int> primes;
vector<int> primeK;

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

int maxPower(long num, int p)
{
	int power = 0;
	while(num % p == 0)
	{
		num /= p;
		power++;
	}

	return power;
}

vector<int> primeFactorize(long num)
{
	vector<int> numPrime(MAX);
	for(int prime : primes)
	{
		if(num < prime)
			break;

		numPrime[prime] = maxPower(num, prime);
	}

	return numPrime;
}

bool isDivisible(valarray<long> temp, long k)
{
	vector<int> masterPrime(MAX);
	for(int i = 0; i < temp.size(); i++)
	{
		vector<int> eltPrime = primeFactorize(temp[i]);
		for(int j = 0; j < eltPrime.size(); j++)
		{
			masterPrime[j] += eltPrime[j];
		}
	}

	for(int i = 0; i < masterPrime.size(); i++)
	{
		if(primeK[i] > masterPrime[i])
			return false;
	}

	return true;
}

int cardGame(valarray<long> input, int size, long k)
{
	int i = 0;
	int j = 0;
	int ans = 0;
	while(j < size)
	{
		if(isDivisible(input[slice(i,j-i+1,1)], k))
		{
			i++;
			ans += size-j;
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
	createSieve();
	long k;
	int n;
	cin >> n >> k;	
	primeK = primeFactorize(k);
	valarray<long> input(n);
	for(int i = 0; i < n; i++)
		cin >> input[i];

	cout << cardGame(input, n, k) << endl;

	return 0;
}