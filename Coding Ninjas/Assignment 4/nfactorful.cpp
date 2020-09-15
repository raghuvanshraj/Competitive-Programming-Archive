#include <iostream>
#define COL 1000001
#define ROW 11

using namespace std;

int table[ROW][COL];

int* constructSieve()
{
	int *sieve = new int[COL];
	for(int i = 0; i < COL; i++)
	{
		sieve[i] = 0;
	}

	for(int i = 2; i < COL; i++)
	{
		if(sieve[i] == 0)
		{
			sieve[i] = 1;
			for(int j = i*2; j < COL; j += i)
			{
				sieve[j]++;
			}
		}
	}

	return sieve;
}

void constructTable()
{
	int *sieve = constructSieve();
	for(int i = 0; i < ROW; i++)
	{
		table[i][0] = 0;
	}

	for(int i = 0; i < ROW; i++)
	{
		for(int j = 1; j < COL; j++)
		{
			if(sieve[j] == i)
			{
				table[i][j] = table[i][j-1]+1;
			}
			else
			{
				table[i][j] = table[i][j-1];
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	constructTable();
	while(t--)
	{
		int a,b,n;
		cin >> a >> b >> n;
		cout << table[n][b] - table[n][a-1] << endl;
	}
	return 0;
}