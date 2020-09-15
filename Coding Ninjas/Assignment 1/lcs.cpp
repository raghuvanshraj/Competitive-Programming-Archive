#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> longestSubsequence(int* arr, int n)
{
	vector<int> input(arr, arr+n);
	vector<int> output;
	sort(input.begin(), input.end());
	for(int i = 0; i < n; i++)
	{
		cout << input[i] << " ";
	}
	cout << endl;
	int start = 0;
	int end = 1;
	for(; end < n+1; end++)
	{
		int diff;
		if(end == n or input[end]-input[end-1] != 1)
		{
			diff = end-start;
			if(diff > output.size())
			{
				output.assign(input.begin()+start, input.begin()+end);
			}
			
			else if(diff == output.size())
			{
				if(find(arr, arr+n, output[0])-arr > find(arr, arr+n, input[start])-arr)
				{
					output.assign(input.begin()+start, input.begin()+end);
				}
			}
			start = end;
		}
	}
	
	return output;
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0 ; i < n; i++)
		cin >> arr[i];
	vector<int> output = longestSubsequence(arr, n);
	vector<int>::iterator itr;
	for(itr = output.begin(); itr != output.end(); itr++)
		cout << *itr << " ";
	return 0;
}
