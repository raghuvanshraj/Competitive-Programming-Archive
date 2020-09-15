#include <iostream>
#define MAX 1000000

using namespace std;
typedef unsigned long long ull;

ull fib[MAX+1];

void calcFib(ull n)
{
	fib[0] = 0;
	fib[1] = 1;
	for(ull i = 2; i <= n; i++)
		fib[i] = fib[i-1]+fib[i-2];
}

int main()
{
	ull n;
	cin >> n;
	calcFib(n);
	cout << fib[n];
}