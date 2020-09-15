#include <bits/stdc++.h>

using namespace std;

vector<int> getBFSPath(int **edges, int n, int v1, int v2) {
	queue<int> vertices;
	bool *isVisited = new bool[n]();
	int *parent = new int[n]();
	vertices.push(v1);
	while (not vertices.empty()) {
		int currVertex = vertices.front();
		isVisited[currVertex] = true;
		vertices.pop();
		for (int i = 0; i < n; ++i) {
			if (edges[currVertex][i] and not isVisited[i]) {
				vertices.push(i);
				parent[i] = currVertex;
				isVisited[i] = true;
			}
		}
	}

	vector<int> bfsPath;
	if (not isVisited[v2]) {
		return bfsPath;
	}

	int curr = v2;
	while (curr != v1) {
		bfsPath.push_back(curr);
		curr = parent[curr];
	}

	bfsPath.push_back(v1);

	return bfsPath;
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

	vector<int> bfsPath = getBFSPath(edges, n, v1, v2);
	for (int i = 0; i < bfsPath.size(); ++i) {
		cout << bfsPath[i] << ' ';
	}

	return 0;
}