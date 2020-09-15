/**
 *    author:	vulkan
 *    created:	27.10.2019 12:44:05 PM
**/
#include <bits/stdc++.h>

using namespace std;

class graph_t {
	vector<int> *adj_list;
	int num_vertices;
public:
	graph_t(int n);
	~graph_t();

	void add_edge(int i, int j);
	bool is_bipartite();
	bool bfs(int start);
};

graph_t::graph_t(int n) {
	this->num_vertices = n;
	this->adj_list = new vector<int>[this->num_vertices]();
}

graph_t::~graph_t() {
	delete [] this->adj_list;
}

void graph_t::add_edge(int i, int j) {
	this->adj_list[i].push_back(j);
	this->adj_list[j].push_back(i);
}

bool graph_t::is_bipartite() {
	return this->bfs(0);
}

bool graph_t::bfs(int start) {
	bool *is_visited = new bool[this->num_vertices]();
	queue<int> qu;
	qu.push(start);
	int colors[this->num_vertices];
	for (int i = 0; i < this->num_vertices; ++i) {
		colors[i] = -1;
	}

	colors[start] = 0;

	while (not qu.empty()) {
		int curr_vertex = qu.front();
		qu.pop();
		int n = this->adj_list[curr_vertex].size();
		for (int i = 0; i < n; ++i) {
			int adj_vertex = this->adj_list[curr_vertex][i];
			if (colors[adj_vertex] == -1) {
				colors[adj_vertex] = not colors[curr_vertex];
				qu.push(adj_vertex);
			} else if (colors[adj_vertex] == colors[curr_vertex]) {
				return false;
			}
		}
	}

	return true;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int num_pairs;
		cin >> num_pairs;
		set<string> names;
		pair<string, string> string_edges[num_pairs];
		for (int i = 0; i < num_pairs; ++i) {
			cin >> string_edges[i].first >> string_edges[i].second;
			names.insert(string_edges[i].first);
			names.insert(string_edges[i].second);
		}

		unordered_map<string, int> names_idx;
		int counter = 0;
		for (auto it = names.begin(); it != names.end(); ++it) {
			names_idx[*it] = counter++;
		}

		graph_t graph(names.size());
		for (int i = 0; i < num_pairs; ++i) {
			graph.add_edge(names_idx[string_edges[i].first], names_idx[string_edges[i].second]);
		}

		string ans = (graph.is_bipartite()) ? "Yes" : "No";
		cout << "Case #" << i + 1 << ": " << ans << endl;
	}

	return 0;
}