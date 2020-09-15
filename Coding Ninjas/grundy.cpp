#include <bits/stdc++.h>

using namespace std;

int max(int a, int b, int c)
{
	return max(max(a,b), c);
}

int mex(int a, int b, int c)
{
	int lim = max(a,b,c);
	for (int i = 0; i < lim; ++i)
	{
		if (i != a and i != b and i != c)
		{
			return i;
		}
	}

	return lim+1;
}

int grundy(int n)
{
	if (n == 0)
	{
		return 0;
	}

	return mex(floor(grundy(n/2)), floor(grundy(n/3)), floor(grundy(n/6)));
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << grundy(n);
	return 0;
}