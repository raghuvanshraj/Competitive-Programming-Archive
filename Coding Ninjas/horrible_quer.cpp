#include <bits/stdc++.h>

using namespace std;

void updateTree(long long *tree, long long *lazy, long long start, long long end, long long node, long long left, long long right, long long inc)
{
	if (start > end)
	{
		return;
	}
	if (lazy[node] != 0)
	{
		tree[node] += lazy[node]*(end-start+1);
		if (start != end)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}

		lazy[node] = 0;
	}

	if (start > right or end < left)
	{
		return;
	}
	else if (start >= left and end <= right)
	{
		tree[node] += inc*(end-start+1);
		if (start != end)
		{
			lazy[2*node] += inc;
			lazy[2*node+1] += inc;
		}
		return;
	}

	long long mid = (start+end) / 2;
	updateTree(tree, lazy, start, mid, 2*node, left, right, inc);
	updateTree(tree, lazy, mid+1, end, 2*node+1, left, right, inc);

	tree[node] = tree[2*node] + tree[2*node+1];
}

long long query(long long *tree, long long *lazy, long long start, long long end, long long node, long long left, long long right)
{
	if (start > end)
	{
		return 0;
	}
	if (lazy[node] != 0)
	{
		tree[node] += lazy[node]*(end-start+1);
		if (start != end)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}

		lazy[node] = 0;
	}

	if (start > right or end < left)
	{
		return 0;
	}
	else if (start >= left and end <= right)
	{
		return tree[node];
	}

	long long mid = (start+end) / 2;
	long long leftAns = query(tree, lazy, start, mid, 2*node, left, right);
	long long rightAns = query(tree, lazy, mid+1, end, 2*node+1, left, right);

	return leftAns + rightAns;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,c;
		cin >> n >> c;
		long long *tree = new long long[4*n]();
		long long *lazy = new long long[4*n]();
		while (c--)
		{
			int type;
			cin >> type;
			switch (type)
			{
				case 0:
				{
					long long l,r,inc;
					cin >> l >> r >> inc;
					updateTree(tree, lazy, 0, n-1, 1, l-1, r-1, inc);
				}
				break;

				case 1:
				{
					long long l,r;
					cin >> l >> r;
					cout << query(tree, lazy, 0, n-1, 1, l-1, r-1) << endl;
				}
				break;
			}
		}
	}

	return 0;
}