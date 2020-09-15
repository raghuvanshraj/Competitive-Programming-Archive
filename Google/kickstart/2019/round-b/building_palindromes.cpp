/**
 *    author:	vulkan
 *    created:	31.10.2019 06:08:28 PM
**/
#include <bits/stdc++.h>
#define MAX_CHARS 26

using namespace std;

class fenwick_tree_t {
	int **tree;
	int tree_size;
public:
	fenwick_tree_t(int n);
	~fenwick_tree_t();
	void update(int idx, char c, int val);
	int query(int idx, int i);
};

fenwick_tree_t::fenwick_tree_t(int n) {
	this->tree_size = n + 1;
	tree = new int*[this->tree_size]();
	for (int i = 0; i < this->tree_size; ++i) {
		tree[i] = new int[MAX_CHARS]();
	}
}

fenwick_tree_t::~fenwick_tree_t() {
	for (int i = 0; i < this->tree_size; ++i) {
		delete [] this->tree[i];
	}

	delete [] tree;
}

void fenwick_tree_t::update(int idx, char c, int val) {
	while (idx < this->tree_size) {
		this->tree[idx][c - 'A'] += val;
		idx += (idx & -idx);
	}
}

int fenwick_tree_t::query(int idx, int i) {
	int ans = 0;
	while (idx > 0) {
		ans += this->tree[idx][i];
		idx -= (idx & -idx);
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int n, q;
		cin >> n >> q;
		fenwick_tree_t fenwick_tree(n);
		string s;
		cin >> s;
		for (int i = 0; i < n; ++i) {
			fenwick_tree.update(i + 1, s[i], 1);
		}

		int ans = 0;
		while (q--) {
			int l, r;
			cin >> l >> r;
			int count = 0;
			for (int i = 0; i < MAX_CHARS; ++i) {
				count += ((fenwick_tree.query(r, i) - fenwick_tree.query(l - 1, i)) % 2);
			}

			if (count <= 1) {
				ans++;
			}
		}

		cout << "Case #" << t + 1 << ": " << ans << endl;
	}

	return 0;
}