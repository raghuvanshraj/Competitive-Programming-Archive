#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void strangeOrder(int n)
{
	vector<int> first(n+1,0);
	first[1] = 1;

	for(int i = 2; i < n+1; i++)
	{
		if(first[i] == 0)
		{
			for(int j = 1; i*j < n+1; j++)
			{
				if(first[i*j] == 0)
				{
					first[i*j] = i;
				}
			}
		}
	}

	for(int i = n; i > 0; i--)
	{
		if(first[i] == 0)
			continue;

		vector<int> print;
		cout << i << " ";
		int factor = first[i];
		int next = i;
		while(next >= 0)
		{
			int elt = i;
			while(elt-factor > 1 and factor != 1)
			{
				if(first[elt-factor])
				{
					print.push_back(elt-factor);
				}

				first[elt-factor] = 0;
				elt -= factor;
			}

			if(next == factor)
			{
				sort(print.begin(), print.end(), greater<int>());
				for(int i = 0; i < print.size(); i++)
					cout << print[i] << " ";
				
				print.clear();
				break;
			}

			while(next%factor == 0)
			{
				next /= factor;
			}

			factor = first[next];
		}
	}
}

int main()
{
	int n;
	cin >> n;
	strangeOrder(n);

	return 0;
}