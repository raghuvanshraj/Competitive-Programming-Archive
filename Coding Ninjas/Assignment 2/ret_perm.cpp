#include <iostream>

using namespace std;

int _returnPermutations(string input, string output[], string temp, int pos)
{
	if(input.empty())
	{
		output[pos] = temp;
		return 1;
	}
	
	int count = 0;
	for(int i = 0; i < input.size(); i++)
		count += _returnPermutations(input.substr(0,i)+input.substr(i+1), output, temp+input[i], pos+count);
		
	return count;
}	

int returnPermutations(string input, string output[])
{
	string temp = "";
	int count = _returnPermutations(input, output, temp, 0);
	return count;
}

int main()
{
	string input;
	string *output = new string[100];
	cin >> input;
	int count = returnPermutations(input, output);
	for(int i = 0; i < count; i++)
		cout << output[i] << endl;
	
	return 0;
}
