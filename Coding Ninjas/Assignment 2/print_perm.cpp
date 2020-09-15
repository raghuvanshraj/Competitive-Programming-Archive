#include <iostream>

using namespace std;

void _printPermutations(string input, string output)
{
	if(input.empty())
	{
		cout << output << endl;
		return;
	}
	
	for(int i = 0; i < input.size(); i++)
		_printPermutations(input.substr(0,i)+input.substr(i+1), output+input[i]);
}	

void printPermutations(string input)
{
	string output = "";
	_printPermutations(input, output);
}

int main()
{
	string input;
	cin >> input;
	printPermutations(input);
	return 0;
}
