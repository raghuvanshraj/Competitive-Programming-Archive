#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int _subset(vector<int>::iterator in_itr, int pos, int n, vector<int> *out)
{
	if(pos == n)
	{
		return 1;
	}
	
	int smallSize = _subset(in_itr+1, pos+1, n, out);
	for(int i = 0; i < smallSize; i++)
	{
		out[i+smallSize].insert(out[i+smallSize].begin(), 1, *in_itr);
		for(int j = 0; j < out[i].size(); j++)
		{
			out[i+smallSize].push_back(out[i][j]);
		}
	}
	
	return 2*smallSize;
}

int subset(int input[], int n, int output[][20])
{
	vector<int> in(input, input+n);
	vector<int>::iterator in_itr = in.begin();
	vector<int> *out = new vector<int>[100000];
	int count = _subset(in_itr, 0, n, out);
	for(int i = 0; i < count; i++)
	{
      	output[i][0] = out[i].size();
		for(int j = 0; j < out[i].size(); j++)
		{
			output[i][j+1] = out[i][j];
		}
	}
	
  	return count;
}

int main()
{
	int n;
	cin >> n;
	int input[n];
	int output[100000][20];
	for(int i = 0; i < n; i++)
		cin >> input[i];
		
	int total = subset(input, n, output);
	for(int i = 0; i < total; i++)
	{
		for(int j = 0; j < output[i][0]; j++)
			cout << output[i][j+1] << " ";
			
		cout << endl;
	}
	return 0;
}
