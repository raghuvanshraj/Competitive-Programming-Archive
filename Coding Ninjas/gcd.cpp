#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	int high = max(a,b);
	int low = min(a,b);
	
	if(low == 0)
		return high;
	
	int rem = high%low;
	return gcd(low, rem);
}

int main()
{
	int a;
	int b;
	cin >> a >> b;
	cout << gcd(a,b);
	return 0;
}
