#include <bits/stdc++.h>

using namespace std;

int countSet(int mask, int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (mask & (1 << i))
		{
			count++;
		}
	}

	return count;
}

int main(int argc, char const *argv[])
{
	while(true)
	{
		int a,b;
		cin >> a >> b;
		cout << (a & b) << endl;
	}
	return 0;
}