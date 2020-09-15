#include <bits/stdc++.h>

using namespace std;

struct Pilot
{	
	int captain;
	int assistant;
};

int minimumSalary(Pilot *pilots, int n)
{
	int finalCost = 0;
	bool chosen[n];
	memset(chosen, false, sizeof(bool) * (n));

	for (int j = 0; j < n; ++j)
	{
		if (!chosen[j])
		{
			int minCaptain = INT_MAX;
			chosen[j] = true;
			int prev = -1;
			for (int k = j+1; k < n; ++k)
			{
				if (!chosen[k])
				{
					if (pilots[k].captain < minCaptain)
					{
						if (prev >= 0)
						{
							chosen[prev] = false;
						}
						chosen[k] = true;
						prev = k;
						minCaptain = pilots[k].captain;
					}
				}
			}

			finalCost += pilots[j].assistant + minCaptain;
		}
	}

	return finalCost;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	Pilot *pilots = new Pilot[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> pilots[i].captain >> pilots[i].assistant;
	}
	cout << minimumSalary(pilots, n);
	return 0;
}