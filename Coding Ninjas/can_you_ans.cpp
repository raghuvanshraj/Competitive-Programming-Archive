#include <bits/stdc++.h>
#define MIN -16000

using namespace std;

struct Node
{
	int maxSum = MIN;
	int totalSum = MIN;
	int bps = MIN;
	int bss = MIN;
};

int max(int a, int b, int c)
{
	return max(max(a,b), c);
}

int max(int a, int b, int c, int d, int e)
{
	return max(max(a,b), max(c,d), e);
}

void buildTree(int *arr, Node *tree, int start, int end, int node)
{
	if (start == end)
	{
		tree[node].maxSum = arr[start];
		tree[node].totalSum = arr[start];
		tree[node].bps = arr[start];
		tree[node].bss = arr[start];

		return;
	}

	int mid = (start+end) / 2;
	buildTree(arr, tree, start, mid, 2*node);
	buildTree(arr, tree, mid+1, end, 2*node+1);

	Node left = tree[2*node];
	Node right = tree[2*node+1];

	tree[node].maxSum = max(left.maxSum, 
							right.maxSum, 
							left.totalSum + right.bps, 
							right.totalSum + left.bss, 
							left.bss + right.bps);
	tree[node].totalSum = left.totalSum + right.totalSum;
	tree[node].bps = max(left.bps, left.totalSum + right.bps);
	tree[node].bss = max(right.bss, right.totalSum + left.bss);
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

	Node ret;
	ret.maxSum = max(leftAns.maxSum, 
			  		 rightAns.maxSum, 
			  		 leftAns.totalSum + rightAns.bps, 
   			  		 rightAns.totalSum + leftAns.bss, 
			  		 leftAns.bss + rightAns.bps);
	ret.totalSum = leftAns.totalSum + rightAns.totalSum;
	ret.bps = max(leftAns.bps, leftAns.totalSum + rightAns.bps);
	ret.bss = max(rightAns.bss, rightAns.totalSum + leftAns.bss);

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
	Node *tree = new Node[4*n];
	buildTree(arr, tree, 0, n-1, 1);
	int q;
	cin >> q;
	while (q--)
	{
		int x,y;
		cin >> x >> y;
		Node ans = query(tree, 0, n-1, 1, x-1, y-1);
		cout << ans.maxSum << endl;
	}

	return 0;
}