#include <bits/stdc++.h>

using namespace std;

unordered_map<int,int> countElt;

bool _groupSum(int input[], int size, int k)
{
	if(k < 0)
		return false;
	if(k == 0)
		return true;
	if(size == 0)
		return false;

	bool included = _groupSum(input+countElt[input[0]], size-countElt[input[0]], k-(input[0]*countElt[input[0]]));
	bool excluded = _groupSum(input+countElt[input[0]], size-countElt[input[0]], k);

	return included or excluded;
}

bool subsetSumToKIdentical(int input[], int n, int k)
{
	int sum = accumulate(input, input+n, 0);
	if(sum < k)
		return false;
	else if(sum == k)
		return true;

	for(int i = 0; i < n; i++)
		countElt[input[i]]++;
	sort(input, input+n);
	return _groupSum(input,n,k);
}

int main()
{
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++)
	{
		cin >> input[i];
	}
	int k;
	cin >> k;
	cout << subsetSumToKIdentical(input,n,k);
	return 0;
}