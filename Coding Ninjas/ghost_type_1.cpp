#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ghost(int n, int mask)
{
	ll *dp = new ll[int(pow(2,n))]();
	dp[0] = 1;
	for (int mask = 0; mask < pow(2,n); ++mask)
	{
		for (int j = 0; j < n; ++j)
		{
			if ((mask & (1 << j)) == 0)
			{
				bool valid = true;
				for (int k = 0; k < n; ++k)
				{
					if (((mask & (1 << k)) != 0))
					{
						if (((k+1) & (j+1)) == (j+1))
						{
							valid = false;
							break;
						}
					}
				}
				if (valid)
				{
					dp[mask | (1 << j)] += dp[mask];
				}
			}
		}
	}

	return dp[int(pow(2,n))-1];
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << ghost(n, 0);
	return 0;
}