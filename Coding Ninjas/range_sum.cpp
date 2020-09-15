#include <bits/stdc++.h>

using namespace std;

void update(int *BIT, int index, int value, int n)
{
	for (int i = index; i < n+1; i += ((i) & (-i)))
	{
		BIT[i] += value;
	}
}

int query(int *BIT, int index)
{
	int total = 0;
	for (int i = index; i > 0; i -= ((i) & (-i)))
	{
		total += BIT[i];
	}

	return total;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *arr = new int[n+1]();
	int *BIT = new int[n+1]();
	for (int i = 1; i < n+1; ++i)
	{
		cin >> arr[i];
		update(BIT, i, arr[i], n);
	}
	int start, end;
	cin >> start >> end;
	cout << query(BIT, end) - query(BIT, start-1);
	return 0;
}