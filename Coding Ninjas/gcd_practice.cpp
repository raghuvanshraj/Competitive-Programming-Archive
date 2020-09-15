#include <bits/stdc++.h>

using namespace std;

int gcd(int x, int y)
{
	int high = max(x,y);
	int low = min(x,y);

	if (low == 0)
	{
		return high;
	}

	return gcd(low, high % low);
}

int main(int argc, char const *argv[])
{
	int x,y;
	cin >> x >> y;
	cout << gcd(x,y);
	return 0;
}