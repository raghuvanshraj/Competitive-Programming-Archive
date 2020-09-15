#include <bits/stdc++.h>
#include <iomanip>
#define MAX 1000000

using namespace std;

vector<int> euler(MAX+1);

void eulerTotient(long n)
{
	for(int i = 1; i < n+1; i++)
		euler[i] = i;

	for(int i = 2; i < n+1; i++)
	{
		if(euler[i] == i)
		{
			for(int j = 1; i*j < n+1; j++)
			{
				euler[i*j] *= double(i-1)/double(i);
			}
		}
	}
}

void func(int n)
{
	vector<double> ans(n+1);
	double final = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j += i)
			ans[j] += double(euler[i])/double(i);

		if(i >= 2)
			final += (i * (ans[i] - 1));
	}

	if(final != ceil(final))
	{
		final = ceil(final);
	}
	cout << setprecision(20) << final << endl;
}

int main()
{
	int n;
	eulerTotient(MAX);
	do
	{
		cin >> n;
		if(n == 0)
			break;
		func(n);
	} while(n != 0);

	return 0;
}