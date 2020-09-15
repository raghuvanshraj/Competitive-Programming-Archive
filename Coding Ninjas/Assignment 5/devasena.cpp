#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull devasena(long *input, long n)
{
	
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long n;
		cin >> n;
		long *input = new long[n];
		for(long i = 0; i < n; i++)
			cin >> input[i];

		cout << devasena(input, n) << endl;
	}
}