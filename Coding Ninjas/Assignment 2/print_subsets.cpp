#include <iostream>
#include <string>

using namespace std;

void _printSubsetsOfArray(int input[], int size, string output)
{
	if(size == 0)
	{
		if(!output.empty())
			output = output.substr(1);
		cout << output << endl;
		return;
	}
	
	_printSubsetsOfArray(input+1, size-1, output);
	_printSubsetsOfArray(input+1, size-1, output + " " + to_string(input[0]));
}

void printSubsetsOfArray(int input[], int size)
{
	string output = "";
	_printSubsetsOfArray(input, size, output);
}

int main()
{
	int n;
	cin >> n;
	int input[n];
	for(int i = 0; i < n; i++)
		cin >> input[i];
		
	printSubsetsOfArray(input, n);
	return 0;
}
