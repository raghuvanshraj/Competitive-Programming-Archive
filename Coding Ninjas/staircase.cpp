#include <bits/stdc++.h>

using namespace std;

long staircase(int n)
{
	long *stair = new long[n+1];
	stair[0] = 1;
	stair[1] = 1;
	stair[2] = 2;
	for(int i = 3; i <= n; i++)
	{
		stair[i] = stair[i-1]+stair[i-2]+stair[i-3];
	}

	return stair[n];
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);

	return 0;
}