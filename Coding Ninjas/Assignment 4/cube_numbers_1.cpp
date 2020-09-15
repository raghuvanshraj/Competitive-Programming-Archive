#include <iostream>
#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;

vector<int> nonCubes(MAX);

void createSieve(int n)
{
	//vector<bool> cubesBool(n+1);
	for(int i = 0; i <= n; i++)
		nonCubes[i] = 0;

	for(int i = 2; i <= int(cbrt(n)); i++)
	{
		int temp = pow(i,3);
		if(nonCubes[i] == 0)
		{
			for(int j = temp; j <= n; j += temp)
			{
				nonCubes[j] = -1;
			}
		}
	}

	int k = 1;
	for(int i = 1; i <= n; i++)
	{
		if(nonCubes[i] == 0)
		{
			nonCubes[i] = k++;
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
		//vector<int>::iterator itr = find(nonCubes.begin(), nonCubes.end(), n);
		if(nonCubes[n] == -1)
		{
			cout << "Case " << i << ": Not Cube Free" << endl;
		}
		else
		{
			cout << "Case " << i << ": " << nonCubes[n] << endl;
		}
	}
	return 0;
}
