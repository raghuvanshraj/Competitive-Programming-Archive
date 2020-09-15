#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;
typedef long double ld;
typedef long long ll;

vector<int> primes;

void createSieve()
{
	int *sieve = new int[MAX];
	for(int i = 0; i < MAX; i++)
		sieve[i] = 0;

	for(int i = 2; i < sqrt(MAX); i++)
	{
		if(sieve[i] == 0)
		{
			for(int j = pow(i,2); j < MAX; j += i)
			{
				if(sieve[j] == 0)
					sieve[j] = i;
			}
		}
	}

	for(int i = 2; i < MAX; i++)
	{
		if(sieve[i] == 0)
		{
			primes.push_back(i);
		}
	}
}

double countEuler(ll l, ll r, long k)
{
	double count = 0;
	for(ll i = l; i <= r; i++)
	{
		ld euler = i;
		ll temp = i;
		for(int j = 0; primes[j] <= sqrt(i); j++)
		{
			if(temp % primes[j] == 0)
			{
				euler *= (primes[j]-1);
				euler /= primes[j];
				while(temp % primes[j] == 0)
				{
					temp /= primes[j];
				}
			}
		}

		if(temp != 1)
		{
			euler *= (temp-1);
			euler /= temp;
		}
		if(int(ceil(euler)) % k == 0)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int t;
	createSieve();
	cin >> t;
	while(t--)
	{
		ll l,r;
		long k;
		cin >> l >> r >> k;
		double count = countEuler(l,r,k);
		double ans = count/(r-l+1);
		printf("%0.6f\n", ans);
	}

	return 0;
}