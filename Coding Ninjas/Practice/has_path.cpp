#include <bits/stdc++.h>

using namespace std;

void BFS(int **edges, int n, bool *isVisited, int start) {
	queue<int> vertices;

	vertices.push(start);
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
}

bool hasPath(int **edges, int v1, int v2, int n) {
	bool *isVisited = new bool[n]();
	BFS(edges, n, isVisited, v1);
	return isVisited[v2];
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

	int v1,v2;
	cin >> v1 >> v2;
	string ans = (hasPath(edges, v1, v2, n)) ? "true" : "false";
	cout << ans;

	return 0;
}