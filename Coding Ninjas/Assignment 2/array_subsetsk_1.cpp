#include <iostream>
#include <bits/stdc++.h>

int _subsetK(int input[], int pos, int n, int k, vector<int> *output)
{
	if(pos == n-1)
		return 1;
	if(k <= 0)
		return 0;
		
	_subsetK(input+1, pos+1, n, k-input[0], output);
	

int subsetSumToK(int input[], int n, int output[][50], int k)
{
	vector<int> *out = new vector<int>[1000];
	int count = _subsetK(input, 0, n, k, out);
	
	return count;
}
	

int main()
{
	return 0;
}
