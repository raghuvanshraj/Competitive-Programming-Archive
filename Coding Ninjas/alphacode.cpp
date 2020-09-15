#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;

unordered_map<string,ull> alpha;

ull alphaCode(string n)
{
	if(n.size() == 0)
	{
		return 1;
	}
	if(n[0] == '0')
	{
		return 0;
	}
	if(n.size() == 1)
	{
		alpha[n] = 1;
		return 1;
	}
	if(alpha[n] > 0)
	{
		return alpha[n];
	}

	alpha[n] += alphaCode(n.substr(1)) % MOD;
	if(stoi(n.substr(0,2)) <= 26)
	{
		alpha[n] += alphaCode(n.substr(2)) % MOD;
	}

	return alpha[n];
}

int main()
{
	string n;
	while(true)
	{
		cin >> n;
		if(n == "0")
		{
			break;
		}

		cout << alphaCode(n) << endl;
	}
}