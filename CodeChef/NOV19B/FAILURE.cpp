/**
 *    author:	vulkan
 *    created:	10.11.2019 06:01:49 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define init_arr(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define init_arr2d(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define init_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) arr[i][j][k] = val
#define all(v) v.begin(), v.end()
#define dec(a,t,n) t *a = new t[n]()
#define pb push_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef queue<int> qi;
typedef priority_queue<int> max_heap;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

class graph_t {
	vector<int> *adj_list;
	bool *vertex_removed;
	int num_vertices;
public:
	graph_t(int n);
	~graph_t();

	void add_edge(int i, int j);
	void remove_vertex(int i);
	void add_vertex(int i);
	bool has_cycle();
	bool _has_cycle(int start, bool *is_visited, int parent);
};

graph_t::graph_t(int n) {
	this->num_vertices = n;
	this->adj_list = new vector<int>[n]();
	this->vertex_removed = new bool[n]();
}

graph_t::~graph_t() {
	delete [] this->adj_list;
	delete [] this->vertex_removed;
}

void graph_t::add_edge(int i, int j) {
	this->adj_list[i].push_back(j);
	this->adj_list[j].push_back(i);
}

void graph_t::remove_vertex(int i) {
	this->vertex_removed[i] = true;
}

void graph_t::add_vertex(int i) {
	this->vertex_removed[i] = false;
}

bool graph_t::_has_cycle(int start, bool *is_visited, int parent) {
	is_visited[start] = true;
	int n = this->adj_list[start].size();
	for (int i = 0; i < n; ++i) {
		int curr_vertex = this->adj_list[start][i];
		if (not this->vertex_removed[curr_vertex]) {
			if (not is_visited[curr_vertex]) {
				if (this->_has_cycle(curr_vertex, is_visited, start)) {
					return true;
				}
			} else if (curr_vertex != parent) {
				return true;
			}
		}
	}

	return false;
}

bool graph_t::has_cycle() {
	dec(is_visited, bool, this->num_vertices);
	for (int i = 0; i < this->num_vertices; ++i) {
		if (not is_visited[i] and not this->vertex_removed[i]) {
			if (this->_has_cycle(i, is_visited, -1)) {
				return true;
			}
		}
	}

	return false;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		graph_t graph(n);
		while (m--) {
			int i, j;
			cin >> i >> j;
			graph.add_edge(i - 1, j - 1);
		}

		if (not graph.has_cycle()) {
			cout << "-1" << endl;
		} else {
			bool solved = false;
			for (int i = 0; i < n; ++i) {
				graph.remove_vertex(i);
				if (not graph.has_cycle()) {
					cout << i + 1 << endl;
					solved = true;
					break;
				}

				graph.add_vertex(i);
			}

			if (not solved) {
				cout << "-1" << endl;
			}
		}
	}

	return 0;
}