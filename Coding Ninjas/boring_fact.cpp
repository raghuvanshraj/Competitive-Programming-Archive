#include <iostream>

using namespace std;
typedef unsigned long long ull;

ull modRecursive(ull a, ull b, ull c)
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

ull wilson(long n, long p)
{
	ull mod = 1;
	for(int i = 1; i < p-n; i++)
	{
		mod = (mod * modRecursive(n+i,p-2,p)) % p;
	}

	return p-mod;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long n;
		long p;
		cin >> n >> p;
		if(n >= p)
		{
			cout << "0" << endl;
			continue;
		}
		cout << wilson(n,p) << endl;
	}
}