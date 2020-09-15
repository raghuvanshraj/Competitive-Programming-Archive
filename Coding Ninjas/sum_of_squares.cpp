#include <bits/stdc++.h>

using namespace std;

struct Node
{
	long long squares = 0;
	long long sum = 0;
};

struct LazyNode
{
	long long set = 0;
	long long increment = 0;
};

void buildTree(long long *arr, Node *tree, long long start, long long end, long long node)
{
	if (start == end)
	{
		tree[node].squares = pow(arr[start], 2);
		tree[node].sum = arr[start];

		return;
	}

	long long mid = (start+end) / 2;
	buildTree(arr, tree, start, mid, 2*node);
	buildTree(arr, tree, mid+1, end, 2*node+1);

	tree[node].squares = tree[2*node].squares + tree[2*node+1].squares;
	tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
}

// Increment Update
void updateTree1(Node *tree, LazyNode *lazy, long long start, long long end, long long node, long long left, long long right, long long inc)
{
	if (start > end)
	{
		return;
	}
	if (lazy[node].set != 0)
	{
		tree[node].squares = pow(lazy[node].set, 2) * (end-start+1);
		tree[node].sum = lazy[node].set * (end-start+1);
		if (start != end)
		{
			lazy[2*node].set = lazy[node].set;
			lazy[2*node+1].set = lazy[node].set;
		}

		lazy[node].set = 0;
	}
	if (lazy[node].increment != 0)
	{
		tree[node].squares += (pow(lazy[node].increment, 2)*(end-start+1)) + (2*lazy[node].increment*tree[node].sum);
		tree[node].sum += lazy[node].increment * (end-start+1);
		if (start != end)
		{
			lazy[2*node].increment += lazy[node].increment;
			lazy[2*node+1].increment += lazy[node].increment;
		}

		lazy[node].increment = 0;
	}

	if (start > right or end < left)
	{
		return;
	}
	else if (start >= left and end <= right)
	{
		tree[node].squares += (pow(inc, 2) * (end-start+1)) + (2 * inc * tree[node].sum);
		tree[node].sum += inc * (end-start+1);
		if (start != end)
		{
			lazy[2*node].increment += inc;
			lazy[2*node+1].increment += inc;
		}
		return;
	}

	long long mid = (start+end) / 2;
	updateTree1(tree, lazy, start, mid, 2*node, left, right , inc);
	updateTree1(tree, lazy, mid+1, end, 2*node+1, left, right, inc);

	tree[node].squares = tree[2*node].squares + tree[2*node+1].squares;
	tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
}

// Set Update
void updateTree0(Node *tree, LazyNode *lazy, long long start, long long end, long long node, long long left, long long right, long long elt)
{
	if (start > end)
	{
		return;
	}
	if (lazy[node].set != 0)
	{
		tree[node].squares = pow(lazy[node].set, 2) * (end-start+1);
		tree[node].sum = lazy[node].set * (end-start+1);
		if (start != end)
		{
			lazy[2*node].set = lazy[node].set;
			lazy[2*node+1].set = lazy[node].set;
		}

		lazy[node].set = 0;
	}
	if (lazy[node].increment != 0)
	{
		tree[node].squares += (pow(lazy[node].increment, 2)*(end-start+1)) + (2*lazy[node].increment*tree[node].sum);
		tree[node].sum += lazy[node].increment * (end-start+1);
		if (start != end)
		{
			lazy[2*node].increment += lazy[node].increment;
			lazy[2*node+1].increment += lazy[node].increment;
		}

		lazy[node].increment = 0;
	}

	if (start > right or end < left)
	{
		return;
	}
	else if (start >= left and end <= right)
	{
		if (start != end)
		{
			lazy[2*node].set = elt;
			lazy[2*node+1].set = elt;
			lazy[2*node].increment = 0;
			lazy[2*node+1].increment = 0;
		}
		tree[node].squares = pow(elt, 2) * (end-start+1);
		tree[node].sum = elt * (end-start+1);

		return;
	}

	long long mid = (start+end) / 2;
	updateTree0(tree, lazy, start, mid, 2*node, left, right, elt);
	updateTree0(tree, lazy, mid+1, end, 2*node+1, left, right, elt);

	tree[node].squares = tree[2*node].squares + tree[2*node+1].squares;
	tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
}

Node query(Node *tree, LazyNode *lazy, long long start, long long end, long long node, long long left, long long right)
{
	if (start > end)
	{
		Node ret;
		return ret;
	}
	if (lazy[node].set != 0)
	{
		tree[node].squares = pow(lazy[node].set, 2) * (end-start+1);
		tree[node].sum = lazy[node].set * (end-start+1);
		if (start != end)
		{
			lazy[2*node].set = lazy[node].set;
			lazy[2*node+1].set = lazy[node].set;
		}

		lazy[node].set = 0;
	}
	if (lazy[node].increment != 0)
	{
		tree[node].squares += (pow(lazy[node].increment, 2)*(end-start+1)) + (2*lazy[node].increment*tree[node].sum);
		tree[node].sum += lazy[node].increment * (end-start+1);
		if (start != end)
		{
			lazy[2*node].increment += lazy[node].increment;
			lazy[2*node+1].increment += lazy[node].increment;
		}

		lazy[node].increment = 0;
	}

	if (start > right or end < left)
	{
		Node ret;
		return ret;
	}
	else if (start >= left and end <= right)
	{
		return tree[node];
	}

	long long mid = (start+end) / 2;
	Node leftAns = query(tree, lazy, start, mid, 2*node, left, right);
	Node rightAns = query(tree, lazy, mid+1, end, 2*node+1, left, right);

	Node ret;
	ret.squares = leftAns.squares + rightAns.squares;
	ret.sum = leftAns.sum + rightAns.sum;

	return ret;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cout << "Case " << i << ":\n";
		int n,q;
		cin >> n >> q;
		long long *arr = new long long[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		Node *tree = new Node[4*n]();
		LazyNode *lazy = new LazyNode[4*n]();
		buildTree(arr, tree, 0, n-1, 1);
		while (q--)
		{
			int type;
			cin >> type;
			switch (type)
			{
				case 0:
				{
					int st,nd,x;
					cin >> st >> nd >> x;
					updateTree0(tree, lazy, 0, n-1, 1, st-1, nd-1, x);
				}
				break;

				case 1:
				{
					int st,nd,x;
					cin >> st >> nd >> x;
					updateTree1(tree, lazy, 0, n-1, 1, st-1, nd-1, x);
				}
				break;

				case 2:
				{
					int st,nd;
					cin >> st >> nd;
					Node ans = query(tree, lazy, 0, n-1, 1, st-1, nd-1);
					cout << ans.squares << endl;
				}
				break;
			}
		}
	}
	return 0;
}