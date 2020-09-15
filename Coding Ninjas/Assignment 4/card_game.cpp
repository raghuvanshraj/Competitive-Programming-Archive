#include <iostream>

typedef long long ll;

using namespace std;

int cardGame(long *input, int size, long k)
{
	if(size == 1)
	{
		if(input[0] % k == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	ll product = 1;
	for(int i = 0; i < size; i++)
	{
		product *= input[i];
	}

	if(product % k != 0)
	{
		return 0;
	}

	long count1 = cardGame(input+1, size-1, k);
	long count2 = cardGame(input, size-1, k);

	return count1+count2+1;
}

int main()
{
	int n;
	int k;
	cin >> n >> k;
	long *input = new long[n];
	for(int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	cout << cardGame(input, n, k) << endl;
}