#include <bits/stdc++.h>
#define MAX 100

using namespace std;

bool _checkAB(char s[])
{
	if (s[0] == '\0')
	{
		return true;
	}

	if (s[0] == 'a')
	{
		if (s[1] != '\0' and s[1] != 'a' and !(s[1] == 'b' and s[2] == 'b'))
		{
			return false;
		}
	}
	else if (s[0] == 'b' and s[1] == 'b')
	{
		if (s[2] != '\0' and s[2] != 'a')
		{
			return false;
		}
	}

	return _checkAB(s+1);
}

bool checkAB(char s[])
{
	if (s[0] != 'a')
	{
		return false;
	}

	return _checkAB(s+1);
}

int main(int argc, char const *argv[])
{
	char s[MAX];
	cin >> s;
	cout << checkAB(s);
	return 0;
}