#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll modRecursive(ll a, ll b, ll c)
{
	if(b == 0)
		return 1;

	if(b%2 == 0)
	{
		return modRecursive((a*a)%c,b/2,c);
	}
	else
	{
		return a * modRecursive((a*a)%c,b/2,c) % c;
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		ll a,b,c;
		cin >> a >> b >> c;
		unordered_map<int,int> aFact = primeFactorize(a);
		unordered_map<int,int> bFact = primeFactorize(b);

		for (auto it = bFact.begin(); it != bFact.end(); ++it)
		{
			it->second *= c;
		}

		ll ans = 1;
		for (auto it = aFact.begin(); it != aFact.end(); ++it)
		{
			if (bFact[it->first] > it->second)	
			{
				ans = (ans * modRecursive(it->first, bFact[it->first]-(it->second), MOD)) % MOD;
			}
		}

		cout << ans << endl;
	}

	return 0;
}