#include <iostream>

using namespace std;

bool checkAB(char input[])
{
	if(input[0] == '\0')
		return true;
		
	if(input[0] == 'a')
	{
		if((input[1] != 'b' or input[2] != 'b') and input[1] != 'a' and input[1] != '\0')
			return false;
	}
	else if(input[0] == 'b' and input[1] == 'b')
	{
		if(input[2] != 'a' and input[2] != '\0')
			return false;
	}
	
	return checkAB(input+1);
}

int main()
{
	char input[10];
	cin >> input;
	cout << checkAB(input);
	return 0;
}
