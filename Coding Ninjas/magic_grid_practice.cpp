#include <bits/stdc++.h>

using namespace std;

int magicGrid(int **input, int r, int c)
{
	int **energy = new int*[r]();
	for (int i = 0; i < r; ++i)
	{
		energy[i] = new int[c]();
	}

	energy[r-1][c-1] = 1;
	for (int i = r-2; i >= 0; --i)
	{
		energy[i][c-1] = energy[i+1][c-1] - input[i][c-1];
		if (energy[i][c-1] <= 0)
		{
			energy[i][c-1] = 1;
		}
	}
	for (int i = c-2; i >= 0; --i)
	{
		energy[r-1][i] = energy[r-1][i+1] - input[r-1][i];
		if (energy[r-1][i] <= 0)
		{
			energy[r-1][i] = 1;
		}
	}
	for (int i = r-2; i >= 0; --i)
	{
		for (int j = c-2; j >= 0; --j)
		{
			int front = min(energy[i+1][j], energy[i][j+1]);
			energy[i][j] = front - input[i][j];
			if (energy[i][j] <= 0)
			{
				energy[i][j] = 1;
			}
		}
	}

	return energy[0][0];
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int r,c;
		cin >> r >> c;
		int **grid = new int*[r];
		for (int i = 0; i < r; ++i)
		{
			grid[i] = new int[c];
			for (int j = 0; j < c; ++j)
			{
				cin >> grid[i][j];
			}
		}

		cout << magicGrid(grid,r,c) << endl;
	}
	return 0;
}