#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<string,char> value;

void _printCodes(string input, string output)
{
	if(input.empty())
	{
		cout << output << endl;
		return;
	}
	
	if(input.size() < 2)
	{
		_printCodes(input.substr(1), output+value[input.substr(0,1)]);
	}
	else
	{
		_printCodes(input.substr(1), output+value[input.substr(0,1)]);
		if(stoi(input.substr(0,2)) < 27)
			_printCodes(input.substr(2), output+value[input.substr(0,2)]);
	}
}
		
void printAllPossibleCodes(string input)
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
	
	string output = "";
	
	_printCodes(input, output);
}

int main()
{
	string input;
	cin >> input;
	printAllPossibleCodes(input);
	return 0;
}
