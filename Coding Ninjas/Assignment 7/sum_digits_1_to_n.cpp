#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef unsigned int ui;

ui *a = new ui[10];

ull sumOfDigits(ui n)
{
	if (n < 10)
	{
		return n * (n+1) / 2;
	}

	int d = log10(n);

	ui p = ceil(pow(10, d));

	ui msd = n/p;

	return msd * a[d] + (msd * (msd-1) / 2)*p +  
       	   msd * (1 + n%p) + sumOfDigits(n%p);
}

int main(int argc, char const *argv[])
{
	a[0] = 0;
	a[1] = 45;

	for (int i = 2; i < 10; ++i)
	{
		a[i] = a[i-1] * 10 + 45 * ceil(pow(10, i-1));
	}
	
	while (true)
	{
		int a,b;
		cin >> a >> b;
		if (a == -1)
		{
			break;
		}

		cout << sumOfDigits(b) - sumOfDigits(a-1) << endl;
	}
	return 0;
}