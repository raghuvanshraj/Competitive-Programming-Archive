#include <bits/stdc++.h>

using namespace std;

bool BFS(int **edges, int n) {
	queue<int> vertices;
	bool *isVisited = new bool[n]();

	vertices.push(0);
	while (!vertices.empty()) {
		int currVertex = vertices.front();
		isVisited[currVertex] = true;
		vertices.pop();
		for (int i = 0; i < n; ++i) {
			if (edges[currVertex][i] == 1 and not isVisited[i]) {
				vertices.push(i);
				isVisited[i] = true;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (not isVisited[i]) {
			return false;
		}
	}

	return true;
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

	if (BFS(edges, n)) {
		cout << "true";
	} else {
		cout << "false";
	}
	return 0;
}