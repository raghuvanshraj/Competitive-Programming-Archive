#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,k,x;
	cin >> n >> k >> x;
	int *input = new int[1024];
	while (n--)
	{
		int temp;
		cin >> temp;
		input[temp]++;
	}
	
	int *temp = new int[1024];
	while (k--)
	{
		bool convertFirst = true;
		memset(temp, 0, sizeof(int)*1024);
		for (int i = 0; i < 1024; ++i)
		{
			if (input[i] > 0)
			{
				if (input[i] % 2 == 0)
				{
					temp[i] -= input[i]/2;
					temp[i^x] += input[i]/2;
				}
				else
				{
					int toConvert;
					if (convertFirst)
					{
						convertFirst = false;
						toConvert = input[i]/2 + 1;
					}
					else
					{
						convertFirst = true;
						toConvert = input[i]/2;
					}
					temp[i^x] += toConvert;
					temp[i] -= toConvert;
				}
			}
		}

		for (int i = 0; i < 1024; ++i)
		{
			input[i] += temp[i];
		}
	}

	for (int i = 1023; i >= 0; --i)
	{
		if (input[i] > 0)
		{
			cout << i << " ";
			break;
		}
	}
	for (int i = 0; i < 1024; ++i)
	{
		if (input[i] > 0)
		{
			cout << i;
			break;
		}
	}

	return 0;
}