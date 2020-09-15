#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<string,char> value;

int _getCodes(string input, string output[10000], string temp, int pos)
{
	if(input.empty())
	{
		output[pos] = temp;
		return 1;
	}
	
	int count = 0;
	
	if(input.size() < 2)
	{
		count += _getCodes(input.substr(1), output, temp+value[input.substr(0,1)], pos+count);
	}
	else
	{
		count += _getCodes(input.substr(1), output, temp+value[input.substr(0,1)], pos+count);
		if(stoi(input.substr(0,2)) < 27)
			count += _getCodes(input.substr(2), output, temp+value[input.substr(0,2)], pos+count);
	}
	
	return count;
}
		
int getCodes(string input, string output[10000])
{
	string nums[26];
	for(int i = 1; i < 27; i++)
		nums[i-1] = to_string(i);
		
	char c = 'a';
	for(string s : nums)
	{
		value[s] = c;
		c++;
	}
	
	string temp = "";
	
	int count = _getCodes(input, output, temp, 0);
	return count;
}

int main()
{
	string input;
	string output[10000];
	cin >> input;
	int count = getCodes(input, output);
	for(int i = 0; i < count; i++)
		cout << output[i] << endl;
	return 0;
}
