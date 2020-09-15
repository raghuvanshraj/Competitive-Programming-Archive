#include <iostream>
#include <bitset>
#include <string>
#include <cmath>

using namespace std;

int modIterBinary(int a, int b, int c)
{
	string binA = bitset<10>(b).to_string();
	int ans = 1;
	int p = 0;
	for(int i = binA.size()-1; i >= 0; i--)
	{
		ans = (ans * int(pow(a, stoi(binA.substr(i,1)) * pow(2,p)))) % c;
		p++;
	}

	return ans;
}

int main()
{
	cout << modIterBinary(3,1,10);
	return 0;
}