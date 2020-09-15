#include <bits/stdc++.h>

using namespace std;

void buildTree(int* arr, int* tree, int node, int start, int end)
{
	if (start == end)
	{
		tree[node] = arr[start];
		return;
	}

	int mid = (start+end) / 2;
	buildTree(arr, tree, 2*node, start, mid);
	buildTree(arr, tree, 2*node+1, mid+1, end);

	tree[node] = min(tree[2*node], tree[2*node+1]);
}

void updateTree(int* tree, int start, int end, int node, int index, int value)
{
	if (start == end)
	{
		tree[node] = value;
		return;
	}

	int mid = (start+end) / 2;
	if (index > mid)
	{
		updateTree(tree, mid+1, end, 2*node+1, index, value);
	}
	else
	{
		updateTree(tree, start, mid, 2*node, index, value);
	}

	tree[node] = min(tree[2*node], tree[2*node+1]);
}

int query(int* tree, int start, int end, int node, int left, int right)
{
	if (end < left or start > right)
	{
		return INT_MAX;
	}
	else if (start >= left and end <= right)
	{
		return tree[node];
	}

	int mid = (start+end) / 2;
	int ans1 = query(tree, start, mid, 2*node, left, right);
	int ans2 = query(tree, mid+1, end, 2*node+1, left, right);

	return min(ans1, ans2);
}

int main(int argc, char const *argv[])
{
	int n,q;
	cin >> n >> q;
	int* arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int* tree = new int[4*n];
	buildTree(arr, tree, 1, 0, n-1);
	for (int i = 0; i < q; ++i)
	{
		char type;
		cin >> type;
		switch(type)
		{
			case 'q':
				int l,r;
				cin >> l >> r;
				cout << query(tree, 0, n-1, 1, l-1, r-1) << endl;
				break;
			case 'u':
				int x,elt;
				cin >> x >> elt;
				updateTree(tree, 0, n-1, 1, x-1, elt);
				break;
		}
	}
	
	return 0;
}