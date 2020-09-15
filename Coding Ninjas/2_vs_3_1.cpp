#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int value = 0;
	int length = 0;
};

int modRecursive(int a, int b, int c)
{
	if(b == 0)
		return 1;

	if(b%2 == 0)
	{
		return modRecursive((a*a)%c,b/2,c);
	}
	else
	{
		return a * modRecursive((a*a)%c,b/2,c) % c;
	}
}

void buildTree(int *arr, Node *tree, int start, int end, int node)
{
	if (start == end)
	{
		tree[node].value = arr[start];
		tree[node].length = 1;
		return;
	}

	int mid = (start+end) / 2;
	buildTree(arr, tree, start, mid, 2*node);
	buildTree(arr, tree, mid+1, end, 2*node+1);

	Node left = tree[2*node];
	Node right = tree[2*node+1];
	
	left.value = (left.value * modRecursive(2,right.length,3)) % 3;

	tree[node].value = (left.value + right.value) % 3;
	tree[node].length = left.length + right.length;
}

void updateTree(int *arr, Node *tree, int start, int end, int node, int index, int val)
{
	if (start == end)
	{
		arr[index] = val;
		tree[node].value = val;
		return;
	}

	int mid = (start+end) / 2;
	if (index > mid)
	{
		updateTree(arr, tree, mid+1, end, 2*node+1, index, val);
	}
	else
	{
		updateTree(arr, tree, start, mid, 2*node, index, val);
	}

	Node left = tree[2*node];
	Node right = tree[2*node+1];

	left.value = (left.value * modRecursive(2,right.length,3)) % 3;

	tree[node].value = (left.value + right.value) % 3;
	tree[node].length = left.length + right.length;
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

	leftAns.value = (leftAns.value * modRecursive(2,rightAns.length,3)) % 3;

	Node ret;
	ret.value = (leftAns.value + rightAns.value) % 3;
	ret.length = leftAns.length + rightAns.length;
	return ret;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string binary;
	cin >> binary;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		arr[i] = stoi(binary.substr(i,1));
	}
	Node *tree = new Node[4*n];
	buildTree(arr, tree, 0, n-1, 1);
	int q;
	cin >> q;
	while (q--)
	{
		int type;
		cin >> type;
		switch (type)	
		{
			case 0:
			{
				int l,r;
				cin >> l >> r;
				Node ans = query(tree, 0, n-1, 1, l, r);
				cout << ans.value << endl;
				break;
			}
			case 1:
			{
				int index;
				cin >> index;
				if (arr[index] == 0)
				{
					updateTree(arr, tree, 0, n-1, 1, index, 1);
				}
				break;
			}
		}
	}

	return 0;
}