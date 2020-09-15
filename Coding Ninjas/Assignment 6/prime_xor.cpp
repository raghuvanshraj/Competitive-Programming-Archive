#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long ll;

bool sieve[9000];

void createSieve()
{
	memset(sieve, true, 9000*sizeof(bool));
	for (int i = 2; i <= sqrt(9000); ++i)
	{
		if (sieve[i])
		{
			for (int j = pow(i,2); j < 9000; j += i)
			{
				sieve[j] = false;
			}
		}
	}
}

ll primeXOR(int *input, int n)
{
	unordered_map<int,int> countElt;
	set<int> distinct;
	for (int i = 0; i < n; ++i)
	{
		distinct.insert(input[i]);
		countElt[input[i]]++;
	}
	ll dp[countElt.size()+1][8192];
	memset(dp, 0, sizeof(ll) * (countElt.size()+1) * 8192);
	dp[0][0] = 1;
	auto it = distinct.begin();
	for (int i = 1; i < countElt.size()+1; ++i,++it)
	{
		int inclusion = (countElt[*it]+1) / 2;
		int exclusion = (countElt[*it]/2) + 1;
		for (int j = 0; j < 8192; ++j)
		{
			dp[i][j] = ((dp[i-1][j] * exclusion) % MOD + (dp[i-1][j^(*it)] * inclusion) % MOD) % MOD;
		}
	}
	ll result = 0;
	for (int i = 2; i < 8192; ++i)
	{
		if (sieve[i])
		{
			result = (result + dp[countElt.size()][i]) % MOD;
		}
	}

	return result;
}

int main(int argc, char const *argv[])
{
	createSieve();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int *input = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> input[i];
		}

		cout << primeXOR(input,n) << endl;
	}
	return 0;
}