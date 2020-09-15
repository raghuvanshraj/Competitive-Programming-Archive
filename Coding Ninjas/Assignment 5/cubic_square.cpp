#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int modRecursive(long a, int b, int c)
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

ull cubicSquare(ull a, string b, int m)
{
	ull result = 1;
	for(int i = b.length()-1; i >= 0; i--)
	{
		if(b[i] == '1')
		{
			result = (result * a) % m;
		}
		else if(b[i] == '2')
		{
			result = (((result * a) % m) * a) % m;
		}

		a = (((a * a) % m) * a) % m;
	}

	return result;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ull a;
		string b;
		int m;

		cin >> a >> b >> m;
		cout << cubicSquare(a,b,m) << endl;
	}
}