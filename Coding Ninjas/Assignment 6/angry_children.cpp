#include <bits/stdc++.h>

using namespace std;

int minCost(long *input, int n, int k)
{
	long *cost = new long[n];
	cost[0] = 0;
	long long sum = input[0];
	for (int i = 1; i < k; ++i)
	{
		cost[i] = cost[i-1] + i*input[i] - sum;
		sum += input[i];
	}
	long min_cost = cost[k-1];
	for (int i = k; i < n; ++i)
	{
		cost[i] = (i-1)*(input[i]+input[i-k]) - 2*(sum-input[i-k]);
		min_cost = min(min_cost, cost[i]);
		sum += input[i]-input[i-k];
	}

	return min_cost;
}

int main(int argc, char const *argv[])
{
	int n,k;
	cin >> n >> k;
	long *input = new long[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}
	sort(input, input+n);
	cout << minCost(input,n,k);
	return 0;
}