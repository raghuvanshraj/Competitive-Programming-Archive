#include <bits/stdc++.h>

using namespace std;

bool checkBalanced(string brackets)
{
	stack<char> st;
	map<char,char> mp;
	mp[']'] = '[';

	for (char br : brackets)
	{
		if (br == '[')
		{
			st.push(br);
		}
		else
		{
			if (!st.empty())
			{
				if (st.top() != mp[br])
				{
					return false;
				}

				st.pop();
			}
			else
			{
				return false;
			}
		}
	}

	if (!st.empty())
	{
		return false;
	}

	return true;
}

int _countProper(int *opening, string brackets, int size, int k, int pos, map<string,int> **dp)
{
	if (dp[size][k][brackets] > 0)
	{
		return dp[size][k][brackets];
	}
	if (size == 0)
	{
		dp[size][k][brackets] = (checkBalanced(brackets)) ? 1 : 0;
		return dp[size][k][brackets];
	}
	if (k == 0)
	{
		dp[size][k][brackets] = _countProper(opening, brackets + "[", size-1, k, pos+1, dp) + 
			   					_countProper(opening, brackets + "]", size-1, k, pos+1, dp);
		return dp[size][k][brackets];
	}

	if (opening[0]-1 == pos)
	{
		dp[size][k][brackets] = _countProper(opening+1, brackets + "[", size-1, k-1, pos+1, dp);
		return dp[size][k][brackets];
	}
	else
	{
		dp[size][k][brackets] = _countProper(opening, brackets + "[", size-1, k, pos+1, dp) + 
			   					_countProper(opening, brackets + "]", size-1, k, pos+1, dp);
		return dp[size][k][brackets];
	}
}

int countProper(int size, int *opening, int k, map<string,int> **dp)
{
	string brackets = "";
	return _countProper(opening, brackets, size, k, 0, dp);
}

int main(int argc, char const *argv[])
{
	int d;
	cin >> d;
	while (d--)
	{
		int n,k;
		cin >> n >> k;
		int *opening = new int[k];
		for (int i = 0; i < k; ++i)
		{
			cin >> opening[i];
		}
		sort(opening, opening+k);
		map<string,int> **dp = new map<string,int>*[2*n + 1]();
		for (int i = 0; i < 2*n + 1; ++i)
		{
			dp[i] = new map<string,int>[k+1]();
		}
		cout << countProper(2*n, opening, k, dp) << endl;
	}
	return 0;
}