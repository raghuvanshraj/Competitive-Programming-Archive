#include <bits/stdc++.h>

using namespace std;

int kadane(string s)
{
	if(s.find('K') == s.npos)
		return s.length()-1;

	int count = 0;
	int best = 0;
	int curr = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == 'R')
		{
			curr -= 1;
			if(curr < 0)
			{
				curr = 0;
			}
			count++;
		}
		else
		{
			curr += 1;
		}

		if(best < curr)
		{
			best = curr;
		}
	}

	return best+count;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		cout << kadane(s) << endl;
	}

	return 0;
}