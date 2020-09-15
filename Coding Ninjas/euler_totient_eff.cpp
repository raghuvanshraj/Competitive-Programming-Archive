#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long double ld;

ull eulerTotient(ull n)
{
	vector<ull> euler(n+1);
	for(ull i = 1; i < n+1; i++)
		euler[i] = i;

	for(ull i = 2; i < n+1; i++)
	{
		if(euler[i] == i)
		{
			for(ull j = 1; i*j < n+1; j++)
			{
				euler[i*j] *= ld(i-1)/ld(i);
			}
		}
	}

	return euler[n];
}

int main()
{
	ull n;
	cin >> n;
	cout << eulerTotient(n);

	return 0;
}