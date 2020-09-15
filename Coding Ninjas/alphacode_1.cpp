#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;

unordered_map<string,ull> alpha;

ull alphaCode(string n)
{
	for(int i = 1; i <= n.size(); i++)
	{
		string sub = n.substr(0,i);
		if(alpha[sub] > 0)
			continue;

		if(i == 1)
		{
			alpha[sub] = 1;
			continue;
		}
		if(sub[i-1] != '0')
			alpha[sub] += (alpha[n.substr(0,i-1)]) % MOD;
		if(stoi(sub.substr(i-2,2)) <= 26 and sub[i-2] != '0')
			alpha[sub] += (alpha[n.substr(0,i-2)]) % MOD;
	}

	return alpha[n] % MOD;
}

int main()
{
	string n;
	alpha[""] = 1;
	while(true)
	{
		cin >> n;
		if(n == "0")
		{
			break;
		}

		cout << alphaCode(n) << endl;
	}

	return 0;
}