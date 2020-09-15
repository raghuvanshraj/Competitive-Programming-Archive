#include <bits/stdc++.h>
const long MOD = 1000000007;

using namespace std;

int balancedBTs(int h)
{
	if (h <= 1)
	{
		return 1;
	}

	int h1 = balancedBTs(h-1);
	int h2 = balancedBTs(h-2);

	return (h1 * ((h1 + (2*h2) % MOD) % MOD) % MOD);
}

int main(int argc, char const *argv[])
{
	int h;
	cin >> h;
	cout << balancedBTs(h);
	return 0;
}