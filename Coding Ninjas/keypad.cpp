#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<char,string> relate;

bool compare(string a, string b)
{
	return (int)a[0] < (int)b[0];
}

int keypad(string input, string* output)
{
	if(input.empty())
		return 1;
		
	int smallOutputSize = keypad(input.substr(1), output);
	string s = relate[input[0]];
	string* temp = new string[smallOutputSize*s.size()];
	int k = 0;
	for(int i = 0; i < smallOutputSize; i++)
	{
		for(int j = 0; j < s.size(); j++)
		{
			temp[k] = s[j] + output[i];
			k++;
		}
	}
	
	for(int i = 0; i < smallOutputSize*s.size(); i++)
		output[i] = temp[i];
	
	//delete temp;
	return smallOutputSize * s.size();
}	
	

int main()
{
	string alpha[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	int i = 0;
	for(char c = '2'; c <= '9'; c++, i++)
		relate[c] = alpha[i];
		
	string input;
	cin >> input;
	int total = 1;
	for(int i = 0; i < input.size(); i++)
	{
		total *= relate[input[i]].size();
	}
	
	string* output = new string[total];
	output[0] = "";
	
	int count = keypad(input, output);
	//sort(output, output+count, compare);
	for(int i = 0; i < count; i++)
		cout << output[i] << endl;
	
	return 0;
}
