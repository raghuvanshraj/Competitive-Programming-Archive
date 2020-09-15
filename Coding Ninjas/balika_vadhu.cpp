#include <bits/stdc++.h>

using namespace std;

int balikaVadhu(string s1, string s2, int k)
{
	int dp[s1.length()+1][s2.length()+1][k+1];
	memset(dp, 0, sizeof(int) * (s1.length()+1) * (s2.length()+1) * (k+1));

	for (int i = 0; i < s1.length()+1; ++i)
	{
		for (int j = 0; j < s2.length()+1; ++j)
		{
			for (int l = 0; l < k+1; ++l)
			{
				if (l == 0)
				{
					dp[i][j][l] = 0;
				}
				else if (i == 0 or j == 0)
				{
					dp[i][j][l] = INT_MIN;
				}
				else if (s1[i-1] == s2[j-1])
				{
					dp[i][j][l] = max(s1[i-1] + dp[i-1][j-1][l-1], dp[i-1][j-1][l]);
				}
				else
				{
					dp[i][j][l] = max(dp[i-1][j][l], dp[i][j-1][l]);
				}
			}
		}
	}

	return dp[s1.length()][s2.length()][k];
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		string s1,s2;
		int k;
		cin >> s1 >> s2 >> k;
		int ans = balikaVadhu(s1, s2, k);
		if (ans < 0)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << ans << endl;
		}
	}
	return 0;
}