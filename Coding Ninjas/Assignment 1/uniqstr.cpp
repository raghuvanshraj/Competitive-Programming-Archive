#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

char* uniqueChar(char *str)
{
    char* output = new char[50000];
    int j = 0;
    for(int i = 0; i < strlen(str); i++)
    {
		char* end = output + sizeof(output)/sizeof(output[0]);
		if(find(output, end, str[i]) == end)
		{
			output[j] = str[i];
			j++;
		}
	}
	
	return output;
}

int main()
{
	char* str = new char[50000];
	cin >> str;
	cout << uniqueChar(str);
	
	return 0;
}
