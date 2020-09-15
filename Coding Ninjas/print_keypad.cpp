#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<char,string> keypad;

void _printKeypad(string input, string output)
{
	if(input.empty())
	{
		cout << output << endl;
		return;
	}
	
	string s = keypad[input[0]];
	
	for(char c : s)
	{
		_printKeypad(input.substr(1), output + c);
	}
}

void printKeypad(int num)
{
	string input = to_string(num);
	_printKeypad(input, "");
}

int main()
{
	string alpha[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	int i = 0;
	for(char c = '2'; c <= '9'; c++, i++)
	{
		keypad[c] = alpha[i];
	}
	
	int num;
	cin >> num;
	printKeypad(num);
	return 0;
}
