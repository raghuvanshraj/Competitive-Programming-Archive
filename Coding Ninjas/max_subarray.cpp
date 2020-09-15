#include <bits/stdc++.h>

using namespace std;

int maxSum(int &start, int &end, vector<int> input)
{
	int max_ending_here = 0;
	int max_so_far = INT_MIN;
	int temp_start = start;
	int temp_end = end;

	for (int i = start; i < end; ++i)
	{
		max_ending_here += input[i];
		if (max_so_far <= max_ending_here)
		{
			max_so_far = max_ending_here;
			temp_end = i+1;
		}
		if (max_ending_here < 0)
		{
			max_ending_here = 0;
			temp_start = i+1;
		}
	}

	start = temp_start;
	end = temp_end;
	return max_so_far;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}

	int start = 0;
	int end = n;
	cout << maxSum(start, end, input) << endl << start << endl << end;

	return 0;
}