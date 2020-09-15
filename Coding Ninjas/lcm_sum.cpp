#include <iostream>
#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;
typedef unsigned long long ull;
typedef long double ld;

vector<ull> euler(MAX+1);
vector<ull> ans(MAX+1);

void eulerTotient(long long n)
{
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
}

void func(long long n)
{
	eulerTotient(n);
	for(long long i = 1; i <= n; i++)
	{
		for(long long j = i; j <= n; j += i)
			ans[j] += i*euler[i];
	}

	cout << (1 + ans[n])*n/2;
}

int main()
{
	long long n;
	cin >> n;
	func(n);
}