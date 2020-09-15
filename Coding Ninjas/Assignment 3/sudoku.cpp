#include <iostream>

using namespace std;

bool isSolved(int board[][9], int &row, int &col)
{
	for(row = 0; row < 9; row++)
	{
		for(col = 0; col < 9; col++)
		{
			if(board[row][col] == 0)
				return false;
		}
	}
	return true;
}

bool checkRow(int board[][9], int row, int val)
{
	for(int i = 0; i < 9; i++)
	{
		if(board[row][i] == val)
			return false;
	}
	return true;
}

bool checkCol(int board[][9], int col, int val)
{
	for(int i = 0; i < 9; i++)
	{
		if(board[i][col] == val)
			return false;
	}
	return true;
}

bool checkGrid(int board[][9], int row, int col, int val)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(board[row+i][col+j] == val)
				return false;
		}
	}
	return true;
}

bool isSafe(int board[][9], int row, int col, int val)
{
	return checkRow(board, row, val) and checkCol(board, col, val) and checkGrid(board, row-(row%3), col-(col%3), val);
}

bool _sudokuSolver(int board[][9])
{
	int row,col;
	if(isSolved(board, row, col))
		return true;
		
	for(int i = 1; i <= 9; i++)
	{
		if(isSafe(board, row, col, i))
		{
			board[row][col] = i;
			
			if(_sudokuSolver(board))
				return true;
				
			board[row][col] = 0;
		}
	}
	return false;
}

bool sudokuSolver(int board[][9])
{	
	return _sudokuSolver(board);
}

int main()
{
	int board[9][9];
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
			cin >> board[i][j];
	}
	cout << sudokuSolver(board);
	return 0;
}
	
