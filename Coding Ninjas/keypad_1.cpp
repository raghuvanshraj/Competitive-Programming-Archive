#include <iostream>
#include <bits/stdc++.h>

using namespace std;

map<int,string> keys;

int keypad(int input, string* output)
{
	if(input == 0)
	{
		return 1;
	}
	
	string s = keys[input%10];
	
	int smallOutputSize = keypad(input/10, output);
	
	int k = 0;
	string* temp = new string[s.size()*smallOutputSize];
	for(int j = 0; j < s.size(); j++)
	{
		for(int i = 0; i < smallOutputSize; i++)
		{
			temp[k] = output[i]+s[j];
			k++;
		}
	}
	for(int i = 0; i < smallOutputSize*s.size(); i++)
		output[i] = temp[i];
	
	return s.size()*smallOutputSize;
}

int main()
{
	string alpha[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	for(int i = 2; i <= 9; i++)
	{
		keys[i] = alpha[i-2];
	}
	int num;
	cin >> num;
	int total = 1;
	int pos = num%10;
	int rem = num/10;
	for(int i = 0; i < to_string(num).size(); i++)
	{
		total *= keys[pos].size();
		pos = rem%10;
		rem /= 10;
	}
	
	string* output = new string[total];
	
	int count = keypad(num, output);
	
	for(int i = 0; i < count; i++)
	{
		cout << output[i] << endl;
	}
	return 0;
}
