#include <bits/stdc++.h>
#define pb(x) push_back(x)

using namespace std;

bool toChange(int *x, int *y, int p, int q, int r)
{
	int x1 = x[q] - x[p];
	int x2 = x[r] - x[q];
	int y1 = y[q] - y[r];
	int y2 = y[r] - y[q];

	int cross = x1*y2 - x2*y1;

	return cross > 0;
}

void getConvexHull(int *x, int *y, int n, bool *visited, vector<int> *convexHull)
{
	int left = 0;
	for (int i = 0; i < n; ++i)
	{
		if (x[left] > x[i])
		{
			left = i;
		}
	}

	convexHull->pb(left);
	visited[left] = true;

	int p = left;
	do
	{
		int q = (p+1) % n;
		while (visited[q] != false)
		{
			q = (p+1) % n;
		}
		for (int i = 0; i < n; ++i)
		{
			if (i == q or visited[i])
			{
				continue;
			}

			if (toChange(x,y,p,q,i))
			{
				q = i;
			}
		}
		visited[q] = true;
		convexHull->pb(q);
		p = q;
	} while (p != left);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	bool *visited = new bool[n]();
	int *x = new int[n]();
	int *y = new int[n]();
	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> y[i];
	}

	vector<int> *convexHull;
	getConvexHull(x, y, n, visited, convexHull);
	for (int i = 0; i < convexHull->size(); ++i)
	{
		cout << x[(*convexHull)[i]] << " " << y[(*convexHull)[i]] << endl;
	}
	return 0;
}