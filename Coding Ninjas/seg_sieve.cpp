#include <iostream>
#include <bits/stdc++.h>
#include <climits>

using namespace std;
typedef long long ll;

vector<ll> primes;

void createSieve(ll n)
{
	bool *sieve = new bool[n+1];
	for(ll i = 0; i < n+1; i++)
		sieve[i] = true;

	for(ll i = 2; i < sqrt(n+1); i++)
	{
		if(sieve[i])
		{
			for(ll j = pow(i,2); j < n+1; j += i)
				sieve[j] = false;
		}
	}

	for(ll i = 2; i < n+1; i++)
	{
		if(sieve[i])
			primes.push_back(i);
	}
}

void segSieve(ll l, ll u)
{
	bool *sieve = new bool[u-l+1];
	for(ll i = 0; i < u-l+1; i++)
		sieve[i] = true;

	for(ll i = 0; primes[i] <= sqrt(u); i++)
	{
		ll base = l - (l % primes[i]);
		if(base < l)
			base += primes[i];
		for(ll j = base; j <= u; j += primes[i])
		{
			sieve[j-l] = false;
		}
		if(base == primes[i])
			sieve[base-l] = true;
	}

	for(ll i = 0; i < u-l+1; i++)
	{
		if(sieve[i])
			cout << i+l << endl;
	}
}

int main()
{
	createSieve(sqrt(INT_MAX));
	int t;
	cin >> t;
	while(t--)
	{
		ll l,u;
		cin >> l >> u;
		segSieve(l,u);
	}

	return 0;
}