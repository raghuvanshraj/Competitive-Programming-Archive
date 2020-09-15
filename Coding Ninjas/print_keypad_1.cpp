#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<int,string> keypad;

void printKeypad(int input, string output)
{
	if(input == 0)
	{
		cout << output << endl;
		return;
	}
	
	string s = keypad[input%10];
	for(char c : s)
	{
		printKeypad(input/10, c + output);
	}
}

int main()
{
	string alpha[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	for(int i = 2; i <= 9; i++)
	{
		keypad[i] = alpha[i-2];
	}
	
	int num;
	cin >> num;
	printKeypad(num, "");
	return 0;
}
