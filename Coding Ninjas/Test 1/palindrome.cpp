#include <bits/stdc++.h>

using namespace std;

int countPalindromeSubstrings(char c[])
{
	string s(c);
	int size = s.size();
	int count = size;
	for(int i = 0; i < size-1; i++)
	{
		for(int j = i+1; j < size; j++)
		{
			string sub = s.substr(i,j-i+1);
			string temp = sub;
			if(sub.size() % 2 == 0)
			{
				string temp = sub.substr(sub.size()/2);
				reverse(temp.begin(), temp.end());
				if(sub.substr(0,sub.size()/2) == temp)
				{
					count++;
				}
			}
			else
			{
				string temp = sub.substr(sub.size()/2 + 1);
				reverse(temp.begin(), temp.end());
				if(sub.substr(0,sub.size()/2) == temp)
				{
					count++;
				}
			}
		}
	}
	return count;
}

int main()
{
	char c[1000];
	cin >> c;
	cout << countPalindromeSubstrings(c);
}