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

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	cout << checkBalanced(s);
	return 0;
}