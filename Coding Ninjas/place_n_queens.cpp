#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int output[11][11];

bool check(int row, int column, int n)
{
	for(int i = 0; i < row; i++)
		if(output[i][column] == 1)
			return false;
		
	int i = row-1;	
	int j = column-1;
	while(i >= 0 and j >= 0)
	{
		if(output[i][j] == 1)
			return false;
		i--;
		j--;
	}
	
	i = row-1;	
	j = column+1;
	while(i >= 0 and j < n)
	{
		if(output[i][j] == 1)
			return false;
		i--;
		j++;
	}
	
	return true;
}

void _placeNQueens(int row, int n)
{
	if(row == n)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				cout << output[i][j] << " ";
		}
		cout << endl;
		return;
	}
	
	for(int j = 0; j < n; j++)
	{
		if(check(row, j, n))
		{
			output[row][j] = 1;
			_placeNQueens(row+1, n);
			output[row][j] = 0;
		}
	}
	return;
}

void placeNQueens(int n)
{
	memset(output, 0, 121*sizeof(int)); 
	_placeNQueens(0, n);
}

int main()
{
	int n;
	cin >> n;
	placeNQueens(n);
	
	return 0;
}
