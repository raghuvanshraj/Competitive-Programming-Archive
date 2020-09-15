#include <bits/stdc++.h>

using namespace std;

struct Count
{
	int evenCount = 0;
	int oddCount = 0;
};

void buildTree(int *arr, Count *tree, int node, int start, int end)
{
	if (start == end)
	{
		if (arr[start] % 2 == 0)
		{
			tree[node].evenCount = 1;
		}
		else
		{
			tree[node].oddCount = 1;
		}

		return;
	}

	int mid = (start+end) / 2;
	buildTree(arr, tree, 2*node, start, mid);
	buildTree(arr, tree, 2*node+1, mid+1, end);

	tree[node].oddCount = tree[2*node].oddCount + tree[2*node+1].oddCount;
	tree[node].evenCount = tree[2*node].evenCount + tree[2*node+1].evenCount;
}

void updateTree(Count *tree, int start, int end, int node, int index, int value)
{
	if (start == end)
	{
		if (value % 2 == 0)
		{
			tree[node].evenCount = 1;
			tree[node].oddCount = 0;
		}
		else
		{
			tree[node].oddCount = 1;
			tree[node].evenCount = 0;
		}

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

	tree[node].oddCount = tree[2*node].oddCount + tree[2*node+1].oddCount;
	tree[node].evenCount = tree[2*node].evenCount + tree[2*node+1].evenCount;
}

Count query(Count *tree, int start, int end, int node, int left, int right)
{
	if (end < left or start > right)
	{
		Count ret;
		ret.oddCount = 0;
		ret.evenCount = 0;
		return ret;
	}
	else if (start >=left and end <= right)
	{
		return tree[node];
	}

	int mid = (start+end) / 2;
	Count ans1 = query(tree, start, mid, 2*node, left, right);
	Count ans2 = query(tree, mid+1, end, 2*node+1, left, right);

	Count ret;
	ret.oddCount = ans1.oddCount + ans2.oddCount;
	ret.evenCount = ans1.evenCount + ans2.evenCount;

	return ret;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	Count *tree = new Count[4*n];
	buildTree(arr, tree, 1, 0, n-1);
	int q;
	cin >> q;
	while (q--)
	{
		int type;
		cin >> type;
		if (type == 0)
		{
			int x,elt;
			cin >> x >> elt;
			updateTree(tree, 0, n-1, 1, x-1, elt);	
		}
		else if (type == 1)
		{
			int l,r;
			cin >> l >> r;
			Count ans = query(tree, 0, n-1, 1, l-1, r-1);
			cout << ans.evenCount << endl;
		}
		else
		{
			int l,r;
			cin >> l >> r;
			Count ans = query(tree, 0, n-1, 1, l-1, r-1);
			cout << ans.oddCount << endl;
		}
	}

	return 0;
}