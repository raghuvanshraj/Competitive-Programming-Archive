#include <bits/stdc++.h>

using namespace std;

void BFS(vector<int> *edges, int n) {
	queue<int> vertices;
	vertices.push(0);
	bool *isVisited = new bool[n]();
	isVisited[0] = true;
	while (not vertices.empty()) {
		int currVertex = vertices.front();
		cout << currVertex << ' ';
		vertices.pop();
		for (int i = 0; i < edges[currVertex].size(); ++i) {
			if (not isVisited[edges[currVertex][i]]) {
				isVisited[edges[currVertex][i]] = true;
				vertices.push(edges[currVertex][i]);
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	int n,m;
	cin >> n >> m;
	vector<int> *edges = new vector<int>[n]();
	for (int i = 0; i < m; ++i) {
		int s,e;
		cin >> s >> e;
		edges[s].push_back(e);
		edges[e].push_back(s);
	}

	for (int i = 0; i < n; ++i) {
		sort(edges[i].begin(), edges[i].end());
	}

	BFS(edges, n);

	return 0;
}