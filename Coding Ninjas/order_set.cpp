#include <bits/stdc++.h>
#define MAX 1000000000

using namespace std;

long BIT[MAX];

void update(int index, int n)
{
	for (int i = index; i < n; i += ((i) & (-i)))
	{
		BIT[i]++;
	}
}

int query(int index)
{
	int total = 0;
	for (int i = index; i > 0; i -= ((i) & (-i)))
	{
		total += BIT[i];
	}

	return total;
}

int main(int argc, char const *argv[])
{
	long q;
	cin >> q;
	vector<long> arr;
	unordered_map<long, int> index;
	memset(BIT, 0, MAX * sizeof(long));
	while (q--)
	{
		char type;
		cin >> type;
		switch(type)
		{
			case 'I':
			{
				int elt;
				cin >> elt;
				if (find(arr.begin(), arr.end(), elt))
				{
					arr.push_back(elt);
					sort(arr.begin(), arr.end());
				}
				break;
			}

			case 'D':
			{
				int elt;
				cin >> elt;
				s.erase(elt);
				break;
			}

			case 'K':
			{
				int pos;
				cin >> pos;
				cout << arr[pos] << endl;
				break;
			}

			case 'C':
			{
				int elt
			}
		}
	}
	return 0;
}