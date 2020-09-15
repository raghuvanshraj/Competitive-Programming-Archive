#include <iostream>
#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

vector<int> nonCubes;

void createSieve(int n)
{
	vector<bool> cubesBool(n+1);
	for(int i = 0; i <= n; i++)
		cubesBool[i] = true;

	for(int i = 2; i <= int(cbrt(n)); i++)
	{
		int temp = pow(i,3);
		if(cubesBool[i])
		{
			for(int j = temp; j <= n; j += temp)
			{
				cubesBool[j] = false;
			}
		}
	}

	for(int i = 1; i <= n; i++)
	{
		if(cubesBool[i])
		{
			nonCubes.push_back(i);
		}
	}
}

int main()
{
	int t;
	createSieve(MAX);
	cin >> t;
	for(int i = 1; i <= t; i++)
	{
		int n;
		cin >> n;
		vector<int>::iterator itr = find(nonCubes.begin(), nonCubes.end(), n);
		if(itr == nonCubes.end())
		{
			cout << "Case " << i << ": Not Cube Free" << endl;
		}
		else
		{
			cout << "Case " << i << ": " << itr-nonCubes.begin()+1 << endl;
		}
	}
	return 0;
}
