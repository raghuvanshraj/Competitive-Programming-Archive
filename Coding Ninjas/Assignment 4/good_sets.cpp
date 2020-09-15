#include <iostream>
#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 1000000

typedef long long ll;

using namespace std;

vector<int> *output = new vector<int>[MAX];

int countGoodSets(int *input, int size)
{
	if(size == 1)
	{
		output[0].push_back(input[0]);
		return 1;
	}

	ll smallCount = countGoodSets(input+1, size-1);

	ll count = 0;
	for(int i = 0; i < smallCount; i++)
	{
		if(output[i][0] % input[0] == 0)
		{
			output[smallCount+count].push_back(input[0]);
			for(ll j = 0; j < output[i].size(); j++)
			{
				output[smallCount+count].push_back(output[i][j]);
			}

			count++;
		}
	}

	output[smallCount+count].push_back(input[0]);

	return smallCount+count+1;
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
		{
			cin >> input[i];
		}
		
		sort(input, input+n);
		ll ans = countGoodSets(input, n);
		for(int i = 0; i < MAX; i++)
		{
			output[i].clear();
		}
		cout << ans << endl;
	}

	return 0;
}