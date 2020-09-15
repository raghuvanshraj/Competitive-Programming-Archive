#include <bits/stdc++.h>

using namespace std;
typedef long double ld;

ld fredo(ld *input, int size)
{
	ld product = 1;
	for(int i = 0; i < size; i++)
	{
		product *= pow(input[i], 0.2);
	}


	if(ceil(product) == product)
	{
		return product+1;
	}

	return ceil(product);
}

int main()
{
	int n;
	cin >> n;
	cout.precision(20);
	ld *input = new ld[n];
	for(int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	cout << fredo(input, n);
}