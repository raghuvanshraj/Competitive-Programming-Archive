#include <bits/stdc++.h>

using namespace std;

int kadane(int *input, int n)
{
	int best = INT_MIN;
	int curr = 0;
	for (int i = 0; i < n; ++i)
	{
		curr += input[i];
		best = max(best, curr);
		if (curr < 0)
		{
			curr = 0;
		}
	}

	return best;
}

int maxRect(int **input, int r, int c)
{
	int final = INT_MIN;
	for (int left = 0; left < c; ++left)
	{
		int *temp = new int[r]();
		for (int right = left; right < c; ++right)
		{
			for (int i = 0; i < r; ++i)
			{
				temp[i] += input[i][right];
			}
			int best = kadane(temp, r);
			final = max(final, best);
		}
	}

	return final;
}

int main(int argc, char const *argv[])
{
	int r,c;
	cin >> r >> c;
	int **input = new int*[r];
	for (int i = 0; i < r; ++i)
	{
		input[i] = new int[c];
		for (int j = 0; j < c; ++j)
		{
			cin >> input[i][j];
		}
	}

	cout << maxRect(input, r, c);

	return 0;
}