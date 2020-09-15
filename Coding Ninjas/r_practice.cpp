#include <bits/stdc++.h>

using namespace std;

int kadane(string s)
{
	if (s.find('K') == s.npos)
	{
		return s.size()-1;
	}
	
	int curr = 0;
	int best = 0;
	int count = 0;

	for (int i = 0; i < s.size(); ++i)
	{
		curr = (s[i] == 'R') ? curr-1 : curr+1;
		if (s[i] == 'R')
		{
			count++;
		}
		if (curr < 0)
		{
			curr = 0;
		}
		best = max(curr, best);
	}

	return best + count;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << kadane(s) << endl;
	}
	return 0;
}