#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s, char c)
{
	int br = 0;
	vector<string> sp;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == c)
		{
			sp.push_back(s.substr(br,i-br));
			br = i+1;
		}
	}
	sp.push_back(s.substr(br));

	return sp;
}


int main()
{
	string s;
	getline(cin, s);
	vector<string> sp = split(s,' ');
	for(int i = 0; i < sp.size(); i++)
		cout << sp[i] << endl;
		
	return 0;
}
