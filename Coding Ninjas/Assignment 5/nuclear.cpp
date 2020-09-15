#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

long fact(long num, long m)
{
	long f = 1;
	for(long i = 2; i <= num; i++)
	{
		f = (f * i) % m;
	}

	return f;
}

int main()
{
	long n;
	cin >> n;
	while(n--)
	{
		ull t;
		long m;
		cin >> t >> m;
		long ans = fact(t%m,m);
		long mult = 1;
		if(t >= m and (t/m) % 2 == 1)
			mult = m-1;

		cout << (mult*ans) % m << endl;
	}
  
  	return 0;
}