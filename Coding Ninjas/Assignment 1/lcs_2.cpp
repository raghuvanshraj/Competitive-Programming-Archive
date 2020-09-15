//Takes O(n) time due to hashing


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> longestSubsequence(int* arr, int n)
{
	unordered_set<int> s;
	vector<int> output;
	for(int i = 0; i < n; i++)
		s.insert(arr[i]);
		
	unordered_set<int>::iterator itr = s.begin();
		
	while(itr != s.end())
	{
		if(s.find(*itr-1) == s.end())
		{
			int start = *itr;
			int end = *itr;
			while(s.find(++end) != s.end());
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


