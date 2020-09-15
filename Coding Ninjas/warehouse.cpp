#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *x = new int[n]();
	int *y = new int[n+2]();
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> y[i+1];
	}
	y[n+1] = 200;
	sort(y, y+n+2);
	int *diff = new int[n+1]();
	for (int i = 0; i < n+1; ++i)
	{
		diff[i] = y[i+1] - y[i];
	}
	sort(diff, diff+n+1, greater<int>());
	cout << diff[0]-1;
	return 0;
}