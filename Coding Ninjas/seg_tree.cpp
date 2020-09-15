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

	tree[node] = tree[2*node] + tree[2*node+1];
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

	tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int* tree, int start, int end, int node, int left, int right)
{
	if (end < left or start > right)
	{
		return 0;
	}
	else if (start >= left and end <= right)
	{
		return tree[node];
	}

	int mid = (start+end) / 2;
	int ans1 = query(tree, start, mid, 2*node, left, right);
	int ans2 = query(tree, mid+1, end, 2*node+1, left, right);

	return ans1 + ans2;
}

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,6,7};
	int* tree = new int[14];
	buildTree(arr, tree, 1, 0, 6);
	for (int i = 0; i < 13; ++i)
	{
		cout << tree[i+1] << endl;
	}
	cout << endl << endl;
	updateTree(tree, 0, 6, 1, 3, 10);
	for (int i = 0; i < 13; ++i)
	{
		cout << tree[i+1] << endl;
	}
	cout << endl << endl;
	// cout << query(tree, 0, 6, 1, 2, 4);
	
	return 0;
}