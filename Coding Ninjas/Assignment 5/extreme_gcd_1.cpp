#include <bits/stdc++.h>
#include <iomanip>
#define MAX 1000000

using namespace std;

vector<int> euler(MAX+1);
vector<double> _ans(MAX+1);


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

int main()
{
	int n;
	eulerTotient(MAX);
	for(int i = 1; i <= MAX; i++)
		for(int j = 2; i*j < MAX; j++)
			_ans[i*j] += i*euler[j];

	for(int i = 2; i <= MAX; i++)
		_ans[i] += _ans[i-1];

	do
	{
		cin >> n;
		if(n == 0)
			break;
		
		cout << setprecision(20) << _ans[n] << endl;
	} while(n != 0);

	return 0;
}