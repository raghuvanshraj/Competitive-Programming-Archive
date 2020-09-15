#include <bits/stdc++.h>

using namespace std;

struct Data
{
	int first = INT_MIN;
	int second = INT_MIN;
};

void buildTree(int *arr, Data *tree, int start, int end, int node)
{
	if (start == end)
	{
		tree[node].first = arr[start];
		tree[node].second = INT_MIN;

		return;
	}

	int mid = (start+end) / 2;
	buildTree(arr, tree, start, mid, 2*node);
	buildTree(arr, tree, mid+1, end, 2*node+1);

	Data left = tree[2*node];
	Data right = tree[2*node+1];

	if (left.first > right.first)
	{
		tree[node].first = left.first;
		tree[node].second = max(left.second, right.first);
	}
	else
	{
		tree[node].first = right.first;
		tree[node].second = max(right.second, left.first);
	}
}

void updateTree(int *arr, Data *tree, int start, int end, int node, int index, int value)
{
	if (start == end)
	{
		arr[index] = value;
		tree[node].first = value;

		return;
	}

	int mid = (start+end) / 2;
	if (index > mid)
	{
		updateTree(arr, tree, mid+1, end, 2*node+1, index, value);
	}
	else
	{
		updateTree(arr, tree, start, mid, 2*node, index, value);
	}

	Data left = tree[2*node];
	Data right = tree[2*node+1];

	if (left.first > right.first)
	{
		tree[node].first = left.first;
		tree[node].second = max(left.second, right.first);
	}
	else
	{
		tree[node].first = right.first;
		tree[node].second = max(right.second, left.first);
	}
}

Data query(Data *tree, int start, int end, int node, int left, int right)
{
	if (end < left or start > right)
	{
		Data ret;
		return ret;
	}
	else if (start >= left and end <= right)
	{
		return tree[node];
	}

	int mid = (start+end) / 2;
	Data leftAns = query(tree, start, mid, 2*node, left, right);
	Data rightAns = query(tree, mid+1, end, 2*node+1, left, right);

	Data ret;
	if (leftAns.first > rightAns.first)
	{
		ret.first = leftAns.first;
		ret.second = max(leftAns.second, rightAns.first);
	}
	else
	{
		ret.first = rightAns.first;
		ret.second = max(rightAns.second, leftAns.first);
	}

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
	Data *tree = new Data[4*n];
	buildTree(arr, tree, 0, n-1, 1);
	int q;
	cin >> q;
	while (q--)
	{
		char type;
		cin >> type;
		switch (type)
		{
			case 'U':
				int x,elt;
				cin >> x >> elt;
				updateTree(arr, tree, 0, n-1, 1, x-1, elt);
				break;
			case 'Q':
				int l,r;
				cin >> l >> r;
				Data ans = query(tree, 0, n-1, 1, l-1, r-1);
				cout << ans.first + ans.second << endl;
				break;
		}
	}
	return 0;
}