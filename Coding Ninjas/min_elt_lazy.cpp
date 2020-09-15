#include <bits/stdc++.h>

using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int node)
{
	if (start == end)
	{
		tree[node] = arr[start];
		return;
	}

	int mid = (start+end) / 2;
	buildTree(arr, tree, start, mid, 2*node);
	buildTree(arr, tree, mid+1, end, 2*node+1);

	tree[node] = min(tree[2*node], tree[2*node+1]);
}

void updateTree(int *tree, int *lazy, int start, int end, int node, int left, int right, int inc)
{
	if (start > end)
	{
		return;
	}
	if (lazy[node] != 0)
	{
		tree[node] += lazy[node];
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
		tree[node] += inc;
		if (start != end)
		{
			lazy[2*node] += inc;
			lazy[2*node+1] += inc;
		}
		return;
	}

	int mid = (start+end) / 2;
	updateTree(tree, lazy, start, mid, 2*node, left, right, inc);
	updateTree(tree, lazy, mid+1, end, 2*node+1, left, right, inc);

	tree[node] = min(tree[2*node], tree[2*node+1]);
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,-3,5,-9,10};
	int n = sizeof(arr)/sizeof(int);
	int *tree = new int[4*n]();
	buildTree(arr, tree, 0, n-1, 1);
	int *lazy = new int[4*n]();
	updateTree(tree, lazy, 0, 4, 1, 0, 2, 2);
	updateTree(tree, lazy, 0, 4, 1, 2, 4, -3);
	cout << "Segment Tree" << endl;
	for (int i = 1; i < 4*n; ++i)
	{
		cout << tree[i] << endl;
	}
	cout << endl << endl;
	cout << "Lazy Tree" << endl;
	for (int i = 1; i < 4*n; ++i)
	{
		cout << lazy[i] << endl;
	}

	return 0;
}