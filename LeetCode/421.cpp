/**
 *    author:	vulkan
 *    created:	22.01.2022 11:25:12 AM
**/
#include <bits/stdc++.h>

using namespace std;

class TrieNode {
	int elt;
	vector<TrieNode*> next;
public:
	TrieNode() {
		elt = -1;
		next = vector<TrieNode*>(2);
	}

	TrieNode* add_child(int x) {
		TrieNode *child = get_child(x);
		if (child) {
			return child;
		}

		child = new TrieNode();
		next[x] = child;
		return child;
	}

	TrieNode* get_child(int x) {
		return next[x];
	}

	void set_elt(int x) {
		elt = x;
	}

	int get_elt() {
		return elt;
	}
};

class Trie {
	TrieNode *root;
	int max_shift;
public:
	Trie() {
		root = new TrieNode();
		max_shift = 30;
	}

	void insert(int x) {
		TrieNode *curr = root;
		int shift = max_shift;
		while (shift >= 0) {
			curr = curr->add_child((x >> shift) & 1);
			shift--;
		}
		curr->set_elt(x);
	}

	int _parse_branch(TrieNode *curr, int x, int shift) {
		if (not curr) {
			return -1;
		}
		if (curr->get_elt() != -1) {
			return curr->get_elt();
		}

		int pref_bit = !((x >> shift) & 1);
		int opt = _parse_branch(curr->get_child(pref_bit), x, shift - 1);
		if (opt != -1) {
			return opt;
		}
		return _parse_branch(curr->get_child(!pref_bit), x, shift - 1);
	}

	int parse_branch(int x) {
		return x ^ _parse_branch(root, x, max_shift);
	}
};

int findMaximumXOR(vector<int> &arr) {
	Trie trie;
	for (int x : arr) {
		trie.insert(x);
	}

	int max_xor = 0;
	for (int x : arr) {
		max_xor = max(max_xor, trie.parse_branch(x));
	}

	return max_xor;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << findMaximumXOR(arr);

	return 0;
}