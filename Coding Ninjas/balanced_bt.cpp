#include <iostream>

using namespace std;

const long MOD = 1000000007;

int balancedBTs(int h)
{
	if(h <= 1)
		return 1;
		
	int h1 = balancedBTs(h-1);
	int h2 = balancedBTs(h-2);
		
	return (h1 * ((((2*h2) % MOD) + h1) % MOD)) % MOD;
}

int main()
{
	int n;
	cin >> n;
	cout << MOD;
	//~ cout << balancedBTs(n);
	
	return 0;
}
