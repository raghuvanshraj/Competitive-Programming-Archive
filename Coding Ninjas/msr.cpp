#include <bits/stdc++.h>

using namespace std;

int kadane(int *input, int size)
{
	int best = INT_MIN;
	int curr = 0;
	for(int i = 0; i < size; i++)
	{
		curr += input[i];
		if(best < curr)
		{
			best = curr;
		}
		if(curr < 0)
		{
			curr = 0;
		}
	}
	
	return best;
}

int maxRect(int **input, int r, int c)
{
	int finalMax = INT_MIN;
	for(int left = 0; left < c; left++)
	{
		int *temp = new int[c];
		for(int right = left; right < c; right++)
		{
			for(int i = 0; i < r; i++)
			{
				temp[i] += input[i][right];
			}
			int max = kadane(temp,c);

			if(finalMax < max)
			{
				finalMax = max;
			}
		}
	}

	return finalMax;
}

int main()
{
	int r,c;
	cin >> r >> c;
	int **input = new int*[r];
	for(int i = 0; i < r; i++)
	{
		input[i] = new int[c];
		for(int j = 0; j < c; j++)
		{
			cin >> input[i][j];
		}
	}

	cout << maxRect(input,r,c);
}