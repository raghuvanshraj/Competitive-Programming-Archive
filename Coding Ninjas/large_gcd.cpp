#include <iostream>
#include <string>

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

int reduce(string a, int b)
{
	int mod = 0;
	
	for(int i = 0; i < a.length(); i++)
	{
		mod = (mod*10 + stoi(a.substr(i,1))) % b;
	}
	
	return mod;
}

void largeGCD(string a, int b)
{
	if(b == 0)
	{
		cout << a << endl;
		return;
	}
	
	int ra = reduce(a,b);
	cout << gcd(ra,b) << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string a;
		int b;
		cin >> b >> a;
		largeGCD(a,b);
	}
	return 0;
}
