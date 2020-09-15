//Takes nlogn time

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> longestSubsequence(int* arr, int n)
{
	vector<int> input(arr, arr+n);
	vector<int> output;
	sort(input.begin(), input.end());
	vector<int>::iterator itr = input.begin();
		
	while(itr != input.end())
	{
		if(find(output.begin(), output.end(), *itr-1) == output.end())
		{
			int start = *itr;
			int end = *itr;
			while(find(input.begin(), input.end(), ++end) != input.end());
			if(end-start > output.size())
			{
				output.clear();
				for(int i = start; i < end; i++)
					output.push_back(i);
			}
			else if(end-start == output.size())
			{
				if(find(arr, arr+n, start)-arr < find(arr, arr+n, output[0])-arr)
				{
					output.clear();
					for(int i = start; i < end; i++)
						output.push_back(i);
				}
			}
		}
		itr++;
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

