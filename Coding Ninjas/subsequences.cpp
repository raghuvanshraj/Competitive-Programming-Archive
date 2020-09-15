#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int subs(string s, string* output)
{
	if(s.empty())
	{
		output[0] = "";
		return 1;
	}
	
	int smallStringSize = subs(s.substr(1), output);
	for(int i = 0; i < smallStringSize; i++)
		output[i+smallStringSize] = s[0]+output[i];
		
	return 2*smallStringSize;
}

int main()
{
	string s;
	cin >> s;
	int size = pow(2,s.size());
	string* output = new string[size];
	int count = subs(s, output);
	for(int i = 0; i < count; i++)
		cout << output[i] << endl;
		
	return 0;
}
