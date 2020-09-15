#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int path[20][20];

void _rat(int maze[][20], int n, int row, int col)
{
	if(row == n-1 and col == n-1)
	{
		path[row][col] = 1;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				cout << path[i][j] << " ";
		}
		cout << endl;
		path[row][col] = 0;
		return;
	}
	if((row == n or col == n) or (row < 0 or col < 0))
		return;
	if(path[row][col] == 1)
		return;
	if(maze[row][col] == 0)
		return;
	
	path[row][col] = 1;
	
	_rat(maze, n, row-1, col);
	_rat(maze, n, row+1, col);
	_rat(maze, n, row, col-1);
	_rat(maze, n, row, col+1);
	
	path[row][col] = 0;
}

void ratInAMaze(int maze[][20], int n)
{
	memset(path, 0, 400*sizeof(int));
	
	_rat(maze, n, 0, 0);
}

int main()
{
	int n;
	cin >> n;
	int maze[n][20];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cin >> maze[i][j];
	}
	
	ratInAMaze(maze, n);
	return 0;
}
