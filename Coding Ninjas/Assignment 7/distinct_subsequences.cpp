#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;

ull distinctSubs(string s)
{
	ull dp[s.size()+1];
	unordered_map<char,ull> lastPos;
	memset(dp, 0, sizeof(ull) * (s.size()+1));
	dp[0] = 1;
	for (ull i = 1; i < s.size()+1; ++i)
	{
		if (lastPos[s[i-1]] > 0)
		{
			dp[i] = (2*dp[i-1] - dp[lastPos[s[i-1]]-1] + MOD) % MOD;
		}
		else
		{
			dp[i] = (2*dp[i-1]) % MOD ;
		}

		lastPos[s[i-1]] = i;
	}

	return dp[s.size()];
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << distinctSubs(s) << endl;
	}
	return 0;
}