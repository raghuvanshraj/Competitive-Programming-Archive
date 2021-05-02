/**
 *    author:	vulkan
 *    created:	13.08.2020 11:27:42 PM
**/
#include <bits/stdc++.h>

using namespace std;

class dsu_t {
	int n;
	vector<int> parent;
public:
	dsu_t(int n);
	int find(int x);
	void merge(int x, int y);
	bool check(int x, int y);
};

dsu_t::dsu_t(int n) {
	this->n = n;
	parent = vector<int>(n);
	for (int i = 0; i <= n - 1; ++i) {
		parent[i] = i;
	}
}

int dsu_t::find(int x) {
	return x == this->parent[x] ? x : this->parent[x] = this->find(parent[x]);
}

void dsu_t::merge(int x, int y) {
	this->parent[this->find(x)] = this->find(y);
}

bool dsu_t::check(int x, int y) {
	return this->find(x) == this->find(y);
}

bool equationsPossible(vector<string> &equations) {
	dsu_t dsu(26);
	for (string eq : equations) {
		if (eq[1] == '=') {
			int x = eq[0] - 'a', y = eq[3] - 'a';
			dsu.merge(x, y);
		}
	}

	for (string eq : equations) {
		if (eq[1] == '!') {
			int x = eq[0] - 'a', y = eq[3] - 'a';
			if (dsu.check(x, y)) {
				return false;
			}
		}
	}

	return true;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<string> equations(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> equations[i];
	}

	cout << equationsPossible(equations);

	return 0;
}