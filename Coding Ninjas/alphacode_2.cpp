#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;

ull alphaCode(int *input, int size)
{
	ull *output = new ull[size+1];
	output[0] = 1;
	output[1] = 1;

	for (int i = 2; i < size+1; ++i)
	{
      	output[i] = 0;
		if(input[i-1] != 0)
			output[i] = (output[i] + output[i-1]) % MOD;
		int temp = input[i-2]*10 + input[i-1];
		if(temp <= 26 and temp >= 10)	
			output[i] = (output[i] + output[i-2]) % MOD;
	}

	return output[size];
}

int main()
{
	string s;
	while(true)
	{
		cin >> s;
		if(s == "0")
			break;

		int *input = new int[s.size()];
		for(int i = 0; i < s.size(); i++)
		{
			input[i] = s[i]-'0';
		}
		
		cout << alphaCode(input, s.size()) << endl;
	}

	return 0;
}