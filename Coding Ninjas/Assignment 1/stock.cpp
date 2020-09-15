#include <iostream>

using namespace std;

int* stockSpan(int *price, int size)
{
	int *output = new int[size];
	for(int i = 0; i < size; i++)
		output[i] = 1;
	for(int i = 1; i < size; i++)
	{
		int j = i-1;
		while(j >= 0)
		{
			if(price[j] < price[i])
			{
				output[i]++;
			}
			else
				break;
				
			j--;
		}
	}
	
	return output;
}

int main()
{
	int size;
	cin >> size;
	int *price = new int[size];
	for(int i = 0; i < size; i++)
		cin >> price[i];
		
	int* output = stockSpan(price, size);
	
	for(int i = 0; i < size; i++)
		cout << output[i] << " ";
		
	return 0;
}
