/**
 *    author:	vulkan
 *    created:	01.09.2019 04:49:06 PM
**/
#include <bits/stdc++.h>

using namespace std;

int recursive_mod(int a, int b, int c) {
	if (b == 0) {
		return 1;
	}

	if (b % 2 == 0) {
		return recursive_mod((a * a) % c, b / 2, c);
	} else {
		return (a * recursive_mod((a * a) % c, b / 2, c)) % c;
	}
}

struct node_t {
	int val = 0;
	int length = 0;
};

class segment_tree_t {
	node_t *tree;
public:
	segment_tree_t(int *arr, int n);
	~segment_tree_t();
	void build_tree(int *arr, int start, int end, int node);
	void update_tree(int start, int end, int node, int idx, int val);
	node_t query(int start, int end, int node, int left, int right);
};

segment_tree_t::segment_tree_t(int *arr, int n) {
	tree = new node_t[4 * n]();
	build_tree(arr, 0, n - 1, 1);
}

segment_tree_t::~segment_tree_t() {
	delete [] tree;
}

void segment_tree_t::build_tree(int *arr, int start, int end, int node) {
	if (start == end) {
		this->tree[node].val = arr[start];
		this->tree[node].length = 1;
		return;
	}

	int mid = (start + end) / 2;
	this->build_tree(arr, mid + 1, end, 2 * node + 1);
	this->build_tree(arr, start, mid, 2 * node);

	node_t left_ans = tree[2 * node];
	node_t right_ans = tree[2 * node + 1];
	left_ans.val = (left_ans.val * recursive_mod(2, right_ans.length, 3)) % 3;
	tree[node].val = (left_ans.val + right_ans.val) % 3;
	tree[node].length = left_ans.length + right_ans.length;
}

void segment_tree_t::update_tree(int start, int end, int node, int idx, int val) {
	if (start == end) {
		tree[node].val = val;
		return;
	}

	int mid = (start + end) / 2;
	if (idx > mid) {
		this->update_tree(mid + 1, end, 2 * node + 1, idx, val);
	} else {
		this->update_tree(start, mid, 2 * node, idx, val);
	}

	node_t left_ans = tree[2 * node];
	node_t right_ans = tree[2 * node + 1];
	left_ans.val = (left_ans.val * recursive_mod(2, right_ans.length, 3)) % 3;
	tree[node].val = (left_ans.val + right_ans.val) % 3;
	tree[node].length = left_ans.length + right_ans.length;
}

node_t segment_tree_t::query(int start, int end, int node, int left, int right) {
	if (start > right or end < left) {
		node_t node;
		return node;
	} else if (start >= left and end <= right) {
		return this->tree[node];
	}

	int mid = (start + end) / 2;
	node_t left_ans = this->query(start, mid, 2 * node, left, right);
	node_t right_ans = this->query(mid + 1, end, 2 * node + 1, left, right);
	node_t ret_node;
	left_ans.val = (left_ans.val * recursive_mod(2, right_ans.length, 3)) % 3;
	ret_node.val = (left_ans.val + right_ans.val) % 3;
	ret_node.length = left_ans.length + right_ans.length;

	return ret_node;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	string bin;
	cin >> bin;
	int *arr = new int[n]();
	for (int i = 0; i < n; ++i) {
		arr[i] = bin[i] - '0';
	}

	segment_tree_t segment_tree(arr, n);

	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		switch (type) {
		case 0: {
			int l, r;
			cin >> l >> r;
			cout << segment_tree.query(0, n - 1, 1, l, r).val << endl;
		}

		break;

		case 1: {
			int idx;
			cin >> idx;
			if (arr[idx] == 0) {
				arr[idx] = 1;
				segment_tree.update_tree(0, n - 1, 1, idx, 1);
			}
		}
		}
	}


	return 0;
}