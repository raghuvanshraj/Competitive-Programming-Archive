#include <iostream>
#include <algorithm>

#define MOD 1000000007
#define MAX 750001

using namespace std;

int countGoodSets(int input[], int size)
{
	int *factors = new int[MAX];
	for(int i = 0; i < MAX; i++)
		factors[i] = 0;
	for(int i = 0; i < size; i++)
		factors[input[i]] = 1;

	for(int i = 0; i < size; i++)
	{
		for(int j = input[i]*2; j < MAX; j += input[i])
		{
			if(factors[j] != 0)
			{
				factors[j] = (factors[j] + factors[input[i]]) % MOD;
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < size; i++)
	{
		ans = (ans + factors[input[i]]) % MOD;
	}

	return ans;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int *input = new int[n];
		for(int i = 0; i < n; i++)
			cin >> input[i];
		sort(input, input+n);
		cout << countGoodSets(input, n) << endl;
	}
}