#include <bits/stdc++.h>

using namespace std;

struct Coder
{
	int x;
	int y;
	int index;
};

bool compareCoderX(Coder a, Coder b)
{
	return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
}

int BIT[100001];

void update(int y)
{
	for (int i = y; i < 100001; i += ((i) & (-i)))
	{
		BIT[i]++;
	}
}

int query(int y)
{
	int total = 0;
	for (int i = y; i > 0; i -= ((i) & (-i)))
	{
		total += BIT[i];
	}

	return total;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	Coder *coders = new Coder[n]();
	for (int i = 0; i < n; ++i)
	{
		cin >> coders[i].x >> coders[i].y;
		coders[i].index = i;
	}
	sort(coders, coders+n, compareCoderX);
	int *ans = new int[n]();
	for (int i = 0; i < n;)
	{
		int endIndex = i;
		while (endIndex < n and coders[i].x == coders[endIndex].x and coders[i].y == coders[endIndex].y)
		{
			endIndex++;
		}

		for (int j = i; j < endIndex; ++j)
		{
			ans[coders[j].index] = query(coders[j].y);
		}

		for (int j = i; j < endIndex; ++j)
		{
			update(coders[j].y);
		}

		i = endIndex;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << ans[i] << endl;
	}
	return 0;
}