#include <bits/stdc++.h>

using namespace std;

int balikaVadhu(string s1, string s2, int k, int i, int j)
{
	if (k == 0)
	{
		return 0;
	}
	if (i == 0 or j == 0)
	{
		return INT_MIN;
	}

	if (s1[i] == s2[j])
	{
		return max(s1[i] + balikaVadhu(s1,s2,k-1,i-1,j-1), balikaVadhu(s1,s2,k,i-1,j-1));
	}
	else
	{
		return max(balikaVadhu(s1,s2,k,i-1,j), balikaVadhu(s1,s2,k,i,j-1));
	}
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
		int ans = balikaVadhu(s1, s2, k, s1.size()-1, s2.size()-1);
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