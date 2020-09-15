#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll countPerm = 0;

void ghostType(int n, int mask, list<int> assigned)
{
	if (mask == int(pow(2,n))-1)
	{
		countPerm++;
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (assigned.empty())
		{
			assigned.push_back(i+1);
			ghostType(n, mask | (1 << (assigned.size()-1)), assigned);
			assigned.pop_back();
			continue;
		}
		if (find(assigned.begin(), assigned.end(), i+1) != assigned.end())
		{
			continue;
		}

		bool flag = true;
		for (auto j = assigned.begin(); j != assigned.end(); ++j)
		{
			if (((*j) & (i+1)) == (i+1))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			assigned.push_back(i+1);
			ghostType(n, mask | (1 << (assigned.size()-1)), assigned);
			assigned.pop_back();
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	list<int> assigned;
	ghostType(n, 0, assigned);
	cout << countPerm;
	return 0;
}