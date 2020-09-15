#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

char* uniqueChar(char *str)
{
    map<char,bool> isVisited;
    for(int i = 0; i < strlen(str); i++)
		isVisited[str[i]] = false;
		
	string output;
	for(int i = 0; i < strlen(str); i++)
	{
		if(isVisited[str[i]] == false)
		{
			isVisited[str[i]] = true;
			output += str[i];
		}
	}
	
	char* output_char;
	strcpy(output_char, output.c_str());
	
	return output_char;
}

int main()
{
	char* str = new char[50000];
	cin >> str;
	char* out = uniqueChar(str);
	cout << out;
	
	return 0;
}
