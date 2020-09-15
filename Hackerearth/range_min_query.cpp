/**
 *    author:	vulkan
 *    created:	23.08.2019 06:22:24 PM
**/
#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
	int *tree;
public:
	SegmentTree(int *arr, int n);
	~SegmentTree();
	void build_tree(int *arr, int start, int end, int node);
	void update_tree(int start, int end, int node, int idx, int val);
	int query(int start, int end, int node, int left, int right);
};

SegmentTree::SegmentTree(int *arr, int n) {
	tree = new int[4 * n];
	build_tree(arr, 0, n - 1, 1);
}

SegmentTree::~SegmentTree() {
	delete [] tree;
}

void SegmentTree::build_tree(int *arr, int start, int end, int node) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	this->build_tree(arr, start, mid, 2 * node);
	this->build_tree(arr, mid + 1, end, 2 * node + 1);

	this->tree[node] = min(this->tree[2 * node], this->tree[2 * node + 1]);
}

void SegmentTree::update_tree(int start, int end, int node, int idx, int val) {
	if (start == end) {
		tree[node] = val;
		return;
	}

	int mid = (start + end) / 2;
	if (idx > mid) {
		this->update_tree(mid + 1, end, 2 * node + 1, idx, val);
	} else {
		this->update_tree(start, mid, 2 * node, idx, val);
	}

	this->tree[node] = min(this->tree[2 * node], this->tree[2 * node + 1]);
}

int SegmentTree::query(int start, int end, int node, int left, int right) {
	if (start >= left and end <= right) {
		return this->tree[node];
	} else if (start > right or end < left) {
		return INT_MAX;
	} else {
		int mid = (start + end) / 2;
		return min(
		           this->query(start, mid, 2 * node, left, right),
		           this->query(mid + 1, end, 2 * node + 1, left, right)
		       );

	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	int *arr = new int[n]();
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	SegmentTree segment_tree(arr, n);

	while (q--) {
		char type;
		cin >> type;
		switch (type) {
		case 'u': {
			int idx, val;
			cin >> idx >> val;
			segment_tree.update_tree(0, n - 1, 1, idx - 1, val);
		}
		break;

		case 'q': {
			int l, r;
			cin >> l >> r;
			cout << segment_tree.query(0, n - 1, 1, l - 1, r - 1) << endl;
		}
		}
	}

	return 0;
}