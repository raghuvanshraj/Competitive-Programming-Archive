#include <iostream>
#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

vector<int> primes;
vector<int> primeK;
vector<int> input;

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
	vector<int> numPrime(num);
	for(int prime : primes)
	{
		if(num < prime)
			break;

		numPrime[prime] = maxPower(num, prime);
	}

	return numPrime;
}

bool isDivisible(int start, int end, int size, long k)
{
	vector<int> masterPrime(size);
	for(int i = start; i <= end; i++)
	{
		vector<int> eltPrime = primeFactorize(input[i]);
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

int cardGame(int size, long k)
{
	int i = 0;
	int j = 0;
	int ans = 0;
	while(j < size)
	{
		if(isDivisible(i,j,size,k))
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
	long elt;
	for(int i = 0; i < n; i++)
	{
		cin >> elt;
		input.push_back(elt);
	}

	cout << cardGame(n, k) << endl;

	return 0;
}