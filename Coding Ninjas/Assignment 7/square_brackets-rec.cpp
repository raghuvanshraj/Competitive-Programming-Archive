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

int _countProper(int *opening, string brackets, int size, int k, int pos)
{
	if (size == 0)
	{
		return (checkBalanced(brackets)) ? 1 : 0;
	}
	if (k == 0)
	{
		return _countProper(opening, brackets + "[", size-1, k, pos+1) + 
			   _countProper(opening, brackets + "]", size-1, k, pos+1);
	}

	if (opening[0]-1 == pos)
	{
		return _countProper(opening+1, brackets + "[", size-1, k-1, pos+1);
	}
	else
	{
		return _countProper(opening, brackets + "[", size-1, k, pos+1) + 
			   _countProper(opening, brackets + "]", size-1, k, pos+1);
	}
}

int countProper(int size, int *opening, int k)
{
	string brackets = "";
	return _countProper(opening, brackets, size, k, 0);
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
		cout << countProper(2*n,opening,k) << endl;
	}
	return 0;
}