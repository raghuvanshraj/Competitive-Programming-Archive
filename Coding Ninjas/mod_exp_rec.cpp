#include <iostream>

using namespace std;

int modRecursive(int a, int b, int c)
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

int main()
{
	cout << modRecursive(0,6,100);
	return 0;
}