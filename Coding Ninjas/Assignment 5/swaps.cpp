#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 1000000

using namespace std;
typedef unsigned long long ull;

vector<ull> fact(MAX+1);
vector<ull> ifact(MAX+1);

ull power(ull x, ull y, long p)
{
    ull res = 1; 
 
    x = x % p;
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y >> 1;
        x = (x*x) % p;  
    }

    return res;
}

ull nCr(int n, int k)
{
	ull ret = ifact[k];
	ret = (ret * ifact[n-k]) % MOD;
	ret = (ret * fact[n]) % MOD;
	return ret;
}

ull inverse(int a, long m)
{
	ull ret = power(a,m-2,m);
	return ret;
}

void calcFactorials()
{
	fact[0] = 1;
	for(int i = 1; i <= MAX; i++)
	{
		fact[i] = (i*fact[i-1]) % MOD;
	}

	ifact[0] = 1;
	for(int i = 1; i <= MAX; i++)
	{
		ifact[i] = (inverse(i,MOD) * ifact[i-1]) % MOD;
	}
}

int main()
{
	int t;
	calcFactorials();
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		ull a = power(2,k,MOD);
		ull b = nCr(n,k);

		cout << (a*b) % MOD << endl;
	}
	return 0;
}