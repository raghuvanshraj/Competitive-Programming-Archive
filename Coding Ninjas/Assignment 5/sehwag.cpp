#include <bits/stdc++.h>
#define MAX 1000001

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

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

vector<double> eulerTotient(ll l, ll r)
{
	vector<double> euler(r-l+1);
	for(ull i = 0; i < r-l+1; i++)
		euler[i] = i+l;

	for(int i = 0; primes[i] <= sqrt(r); i++)
	{
		ull start = l - l%primes[i];
		if(start < l)
			l += primes[i];
		for(ull j = start; j < r-l+1; j += primes[i])
		{
			euler[j] *= double(primes[i]-1)/double(primes[i]);
		}
	}

	return euler;
}

double countEuler(long l, long r, int k)
{
	double count = 0;
	vector<double> euler = eulerTotient(l,r);
	for(int i = 0; i < euler.size(); i++)
	{
		if(euler[i] != ceil(euler[i]))
			euler[i] = ceil(euler[i]);
		if(int(euler[i]) % k == 0)
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
		int k;
		cin >> l >> r >> k;
		double count = countEuler(l,r,k);
		cout << setprecision(6) << count/(r-l+1) << endl;
	}

	return 0;
}