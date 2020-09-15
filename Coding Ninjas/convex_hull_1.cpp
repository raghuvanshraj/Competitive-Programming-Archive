#include <bits/stdc++.h>
#define pb(x) push_back(x)

using namespace std;

bool toChange(int *x, int *y, int p, int q, int r)
{
	int x1 = x[p] - x[q];
	int x2 = x[r] - x[q];
	int y1 = y[p] - y[q];
	int y2 = y[r] - y[q];

	int cross = x1*y2 - x2*y1;

	return cross > 0;
}

void getConvexHull(int *x, int *y, int n)
{
	vector<int> convexHull;
	int left = 0;
	for (int i = 0; i < n; ++i)
	{
		if (x[left] > x[i])
		{
			left = i;
		}
	}

	int p = left;
	do
	{
		convexHull.pb(p);
		int q = (p+1) % n;
		for (int i = 0; i < n; ++i)
		{
			if (i == q)
			{
				continue;
			}

			if (toChange(x,y,p,q,i))
			{
				q = i;
			}
		}
		p = q;
	} while (p != left);

	for (int i = 0; i < convexHull.size(); ++i)
	{
		cout << x[convexHull[i]] << " " << y[convexHull[i]] << endl;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
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

	getConvexHull(x, y, n);

	return 0;
}