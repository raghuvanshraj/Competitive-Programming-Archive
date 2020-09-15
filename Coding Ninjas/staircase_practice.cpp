#include <bits/stdc++.h>

using namespace std;

int staircase(int n)
{
	if (n < 0)
	{
		return 0;
	}
	if (n == 0)
	{
		return 1;
	}

	return staircase(n-1) + staircase(n-2) + staircase(n-3);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << staircase(n);
	return 0;
}