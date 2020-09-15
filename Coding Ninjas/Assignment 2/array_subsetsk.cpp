#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int _subsetSumToK(vector<int>::iterator in_itr, int pos, int n, vector<int> *out)
{
	if(pos == n)
	{
		return 1;
	}
	
	int smallSize = _subsetSumToK(in_itr+1, pos+1, n, out);
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

int subsetSumToK(int input[], int n, int output[][50], int k)
{
	vector<int> in(input, input+n);
	vector<int>::iterator in_itr = in.begin();
	vector<int> *out = new vector<int>[10000];
	int count = _subsetSumToK(in_itr, 0, n, out);
	int sub_count = 0;
	for(int i = 0; i < count; i++)
	{
      	if(accumulate(out[i].begin(), out[i].end(), 0) == k)
      	{
			output[sub_count][0] = out[i].size();
			for(int j = 0; j < out[i].size(); j++)
			{
				output[sub_count][j+1] = out[i][j];
			}
			sub_count++;
		}
	}
	
  	return sub_count;
}


int main()
{
	int n;
	cin >> n;
	int* input = new int[n];
	int output[1000][50];
	int k;
	for(int i = 0; i < n; i++)
		cin >> input[i];
	cin >> k;
		
	int total = subsetSumToK(input, n, output, k);
	for(int i = 0; i < total; i++)
	{
		for(int j = 0; j < output[i][0]; j++)
			cout << output[i][j+1] << " ";
			
		cout << endl;
	}
	
	return 0;
}
