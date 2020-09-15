#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const long MOD = 1000000007;
vector<int> allPrimes;

void sieve(int n)
{
	allPrimes.clear();
	vector<bool> primes(n);
	vector<int> ret;
	for(int i = 0; i <= n; i++)
		primes[i] = true;
		
	for(int i = 2; i <= sqrt(n); i++) {
      	if(primes[i])
        {
            int temp = i;
            for(int j = pow(i,2); j <= n; j = i*(++temp))
                primes[j] = false;
        }
	}
	
	for(int i = 2; i <= n; i++)
	{
		if(primes[i])
		{
			allPrimes.push_back(i);
		}
	}
}

int countDivisors(int n)
{
	long result = 1;
	
	sieve(n);
	
	for(int i = 0; i < allPrimes.size(); i++)
	{
		int p = allPrimes[i];
		int num = n;
		
		int x = 0;
		while(num)
		{
			num /= p;
			x = (x + num) % MOD;
		}
		
		result = (result * (x+1)) % MOD;
	}
	
	return result;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << countDivisors(n) << endl;
	}
	
	return 0;
}
