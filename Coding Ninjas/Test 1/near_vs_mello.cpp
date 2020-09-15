#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll maxWater(int *input, int size)
{
	sort(input, input+size, greater<int>());
	int tallest = input[1];
	ll ans = 0;
	for (int i = 2; i < size; ++i)
	{
		ans += tallest-input[i];
	}

	return ans;
}

int main()
{
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	cout << maxWater(input, n);

	return 0;
}