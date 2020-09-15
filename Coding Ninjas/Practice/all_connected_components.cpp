#include <bits/stdc++.h>

using namespace std;

set<int> BFS(int **edges, int n, int start, bool *isVisited) {
	queue<int> vertices;
	set<int> component;
	vertices.push(start);
	while (not vertices.empty()) {
		int currVertex = vertices.front();
		isVisited[currVertex] = true;
		component.insert(currVertex);
		vertices.pop();
		for (int i = 0; i < n; ++i) {
			if (edges[currVertex][i] and not isVisited[i]) {
				vertices.push(i);
				isVisited[i] = true;
			}
		}
	}

	return component;
}

int main(int argc, char const *argv[]) {
	int n,m;
	cin >> n >> m;
	int **edges = new int*[n]();
	for (int i = 0; i < n; ++i) {
		edges[i] = new int[n]();
	}

	for (int i = 0; i < m; ++i) {
		int s,e;
		cin >> s >> e;
		edges[s][e] = 1;
		edges[e][s] = 1;
	}

	vector<set<int>> components;
	bool *isVisited = new bool[n]();
	for (int i = 0; i < n; ++i) {
		if (not isVisited[i]) {
			components.push_back(BFS(edges, n, i, isVisited));
		}
	}

	for (int i = 0; i < components.size(); ++i) {
		set<int> currComponent = components[i];
		auto it = currComponent.begin();
		while (it != currComponent.end()) {
			cout << *it << ' ';
			it++;
		}

		cout << endl;
	}
	return 0;
}