#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int aValue = INT_MIN;
	int bValue = INT_MAX;
	int index = -1;
};

void buildTree(int *a, int *b, Node *tree, int start, int end, int node)
{
	if (start == end)
	{
		tree[node].aValue = a[start];
		tree[node].bValue = b[start];
		tree[node].index = start;

		return;
	}

	int mid = (start+end) / 2;
	buildTree(a, b, tree, start, mid, 2*node);
	buildTree(a, b, tree, mid+1, end, 2*node+1);

	Node left = tree[2*node];
	Node right = tree[2*node+1];
	Node set;

	if (left.aValue > right.aValue)
	{
		set = left;
	}
	else if (left.aValue < right.aValue)
	{
		set = right;
	}
	else
	{
		if (left.bValue > right.bValue)
		{
			set = right;
		}
		else if (left.bValue < right.bValue)
		{
			set = left;
		}
		else
		{
			set = (left.index < right.index) ? left : right;
		}
	}

	tree[node] = set;
}

Node query(Node *tree, int start, int end, int node, int left, int right)
{
	if (end < left or start > right)
	{
		Node ret;
		return ret;
	}
	else if (start >= left and end <= right)
	{
		return tree[node];
	}

	int mid = (start+end) / 2;
	Node leftAns = query(tree, start, mid, 2*node, left, right);
	Node rightAns = query(tree, mid+1, end, 2*node+1, left, right);
	Node set;

	if (leftAns.aValue > rightAns.aValue)
	{
		set = leftAns;
	}
	else if (leftAns.aValue < rightAns.aValue)
	{
		set = rightAns;
	}
	else
	{
		if (leftAns.bValue > rightAns.bValue)
		{
			set = rightAns;
		}
		else if (leftAns.bValue < rightAns.bValue)
		{
			set = leftAns;
		}
		else
		{
			set = (leftAns.index < rightAns.index) ? leftAns : rightAns;
		}
	}

	return set;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}
	Node *tree = new Node[4*n];
	buildTree(a, b, tree, 0, n-1, 1);
	int q;
	cin >> q;
	while (q--)
	{
		int l,r;
		cin >> l >> r;
		Node ans = query(tree, 0, n-1, 1, l-1, r-1);
		cout << ans.index + 1 << endl;
	}

	return 0;
}