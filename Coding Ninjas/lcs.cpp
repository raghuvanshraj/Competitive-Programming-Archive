#include <bits/stdc++.h>

using namespace std;

int lcs(string s1, string s2)
{
	int dp[s1.length()+1][s2.length()+1];

	for(int i = 0; i < s1.length()+1; i++)
	{
		for(int j = 0; j < s2.length()+1; j++)
		{
			if(i == 0 or j == 0)
			{
				dp[i][j] = 0;
			}
			else if(s1[i-1] == s2[j-1])
			{
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[s1.length()][s2.length()];
}

int main()
{
	string s1;
	string s2;
	cin >> s1 >> s2;
	cout << lcs(s1,s2);
	return 0;
}