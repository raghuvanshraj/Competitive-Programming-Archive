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

int reduce(string y, int x)
{
	int y_int = 0;
	for (int i = 0; i < y.size(); ++i)
	{
		y_int = (y_int * 10 + y[i] - '0') % x;
	}

	return y_int;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int x;
		string y;
		cin >> x >> y;
		if (x == 0)
		{
			cout << y << endl;
			continue;
		}
		int y_int = reduce(y,x);
		cout << gcd(x,y_int) << endl;
	}
	return 0;
}