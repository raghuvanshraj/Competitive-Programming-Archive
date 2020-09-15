#include <bits/stdc++.h>

using namespace std;

int _countPS(string s, int i, int j)
{
	if(j == i+1)
	{
		if(s[i] == s[j])
			return 1;
		else
			return 0;
	}

	int count = 0;
	string sub = s.substr(i,j-i+1);
	string rev = sub;
	reverse(rev.begin(), rev.end());
	if(sub == rev)
		count++;

	count += _countPS(s,i+1,j) + _countPS(s,i,j-1);
	if((j-1)-(i+1)+1 != 1)
	{
		count -= _countPS(s,i+1,j-1);
	}

	return count;
}

int countPalindromeSubstrings(char c[])
{
	string s(c);
	if(s.size() == 1)
		return 1;

	return _countPS(s,0,s.size()-1)+s.size();
}

int main()
{
	char c[1000];
	cin >> c;
	cout << countPalindromeSubstrings(c);

	return 0;
}