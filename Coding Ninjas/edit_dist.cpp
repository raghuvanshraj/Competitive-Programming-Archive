#include <bits/stdc++.h>

using namespace std;

int min(int x, int y, int z)
{
	return min(min(x,y),z);
}

int editDistance(string s1, string s2)
{
	int dp[s1.size()+1][s2.size()+1];
	for(int i = 0; i < s1.size()+1; i++)
	{
		for(int j = 0; j < s2.size()+1; j++)
		{
			if(i == 0)
			{
				dp[i][j] = j;
			}
			else if(j == 0)
			{
				dp[i][j] = i;
			}
			else if(s1[i-1] == s2[j-1])
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
			}
		}
	}

	return dp[s1.size()][s2.size()];
}

int main()
{
	string s1,s2;
	cin >> s1 >> s2;
	cout << editDistance(s1,s2);

	return 0;
}