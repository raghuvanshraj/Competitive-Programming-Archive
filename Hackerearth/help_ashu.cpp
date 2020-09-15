/**
 *    author:	vulkan
 *    created:	23.08.2019 07:08:59 PM
**/
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int even_count = 0;
	int odd_count = 0;
};

TreeNode operator +(TreeNode a, TreeNode b) {
	TreeNode res;
	res.even_count = a.even_count + b.even_count;
	res.odd_count = a.odd_count + b.odd_count;

	return res;
}

class SegmentTree {
	TreeNode *tree;
public:
	SegmentTree(int *arr, int n);
	~SegmentTree();
	void build_tree(int *arr, int start, int end, int node);
	void update_tree(int start, int end, int node, int idx, int val);
	TreeNode query(int start, int end, int node, int left, int right);
};

SegmentTree::SegmentTree(int *arr, int n) {
	tree = new TreeNode[4 * n];
	build_tree(arr, 0, n - 1, 1);
}

SegmentTree::~SegmentTree() {
	delete [] tree;
}

void SegmentTree::build_tree(int *arr, int start, int end, int node) {
	if (start == end) {
		if (arr[start] % 2) {
			tree[node].odd_count = 1;
		} else {
			tree[node].even_count = 1;
		}

		return;
	}

	int mid = (start + end) / 2;
	this->build_tree(arr, start, mid, 2 * node);
	this->build_tree(arr, mid + 1, end, 2 * node + 1);

	this->tree[node] = this->tree[2 * node] + this->tree[2 * node + 1];
}

void SegmentTree::update_tree(int start, int end, int node, int idx, int val) {
	if (start == end) {
		if (val % 2) {
			tree[node].odd_count = 1;
			tree[node].even_count = 0;
		} else {
			tree[node].even_count = 1;
			tree[node].odd_count = 0;
		}

		return;
	}

	int mid = (start + end) / 2;
	if (idx > mid) {
		this->update_tree(mid + 1, end, 2 * node + 1, idx, val);
	} else {
		this->update_tree(start, mid, 2 * node, idx, val);
	}

	this->tree[node] = this->tree[2 * node] + this->tree[2 * node + 1];
}

TreeNode SegmentTree::query(int start, int end, int node, int left, int right) {
	if (start >= left and end <= right) {
		return this->tree[node];
	} else if (start > right or end < left) {
		TreeNode res;
		return res;
	} else {
		int mid = (start + end) / 2;

		return this->query(start, mid, 2 * node, left, right) +
		       this->query(mid + 1, end, 2 * node + 1, left, right);

	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int q;
	cin >> q;

	SegmentTree segment_tree(arr, n);

	while (q--) {
		int type;
		cin >> type;
		switch (type) {
		case 0: {
			int idx, val;
			cin >> idx >> val;
			segment_tree.update_tree(0, n - 1, 1, idx - 1, val);
		}
		break;

		case 1: {
			int l, r;
			cin >> l >> r;
			cout << segment_tree.query(0, n - 1, 1, l - 1, r - 1).even_count << endl;
		}
		break;

		case 2: {
			int l, r;
			cin >> l >> r;
			cout << segment_tree.query(0, n - 1, 1, l - 1, r - 1).odd_count << endl;
		}
		}
	}

	return 0;
}