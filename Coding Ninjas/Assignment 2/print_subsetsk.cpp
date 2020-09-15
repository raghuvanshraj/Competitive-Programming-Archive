#include <iostream>
#include <string>

using namespace std;

void _printSubsetSumToK(int input[], string output, int size, int k)
{
	if(k < 0)
		return;
	if(k == 0)
	{
		cout << output.substr(1) << endl;
		return;
	}
	if(size == 0)
		return;
	
	_printSubsetSumToK(input+1, output+" "+to_string(input[0]), size-1, k-input[0]);
	_printSubsetSumToK(input+1, output, size-1, k);
}

void printSubsetSumToK(int input[], int size, int k)
{
	string output = "";
	_printSubsetSumToK(input, output, size, k);
}

int main()
{
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++)
		cin >> input[i];
	int k;
	cin >> k;
	
	printSubsetSumToK(input, n, k);
	
	return 0;
}
