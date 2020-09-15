#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int count(string s, char c)
{
	string::iterator itr = s.begin();
	int count = 0;
	bool done = false;
	while(!done)
	{
		itr = find(itr, s.end(), c);
		if(itr != s.end())
		{
			count++;
			itr++;
		}
		else
			break;
	}
	
	return count;
}

char nonRepeatingCharacter(string str)
{
	int i;
	for(i = 0; i < str.size(); i++)
	{
		if(count(str, str[i]) == 1)
			return str[i];
	}
	
	return str[0];
}

int main()
{
	string str;
	cin >> str;
	cout << nonRepeatingCharacter(str);
	//~ for(int i = 0; i < str.size(); i++)
		//~ cout << count(str, str[i]) << " ";
	
	return 0;
}
