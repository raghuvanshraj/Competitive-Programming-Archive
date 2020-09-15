#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s)
{
	int br = 0;
	vector<string> sp;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == ' ')
		{
			sp.push_back(s.substr(br,i-br));
			br = i+1;
		}
	}
	sp.push_back(s.substr(br));

	return sp;
}

void _subsetSumToK(int input[], string temp, vector<string> &output, int size, int k)
{
	if(k < 0)
		return;
	if(k == 0)
	{
		output.push_back(temp.substr(1));
		return;
	}
	if(size == 0)
		return;
	
	_subsetSumToK(input+1, temp+" "+to_string(input[0]), output, size-1, k-input[0]);
	_subsetSumToK(input+1, temp, output, size-1, k);
}

int subsetSumToK(int input[], int n, int output[][50], int k)
{
	string temp = "";
	vector<string> out;
	vector<string> curr;
	_subsetSumToK(input, temp, out, n, k);
	for(int i = 0; i < out.size(); i++)
	{
		curr = split(out[i]);
		output[i][0] = curr.size();
		for(int j = 0; j < curr.size(); j++)
			output[i][j+1] = stoi(curr[j]);
	}

	return out.size();
}

int main()
{
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++)
		cin >> input[i];
	int k;
	cin >> k;
	int output[10000][50];
	int count = subsetSumToK(input, n, output, k);
	for(int i = 0; i < count; i++)
	{
		for(int j = 0; j < output[i][0]; j++)
			cout << output[i][j+1] << " ";
		cout << endl;
	}
	
	return 0;
}
