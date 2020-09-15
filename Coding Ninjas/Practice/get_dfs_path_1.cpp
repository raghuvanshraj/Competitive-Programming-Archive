#include <bits/stdc++.h>

using namespace std;

bool DFS(int **edges, int n, int v1, int v2, bool *isVisited) {
	isVisited[v1] = true;

	if (v1 == v2) {
		cout << v1 << ' ';
		return true;
	}

	bool pathFound = false;
	for (int i = 0; i < n; ++i) {
		if (edges[v1][i] == 1 and not isVisited[i]) {
			pathFound = DFS(edges, n, i, v2, isVisited);
			if (pathFound) {
				cout << v1 << ' ';
				return true;
			}
		}
	}

	return false;
}

void getDFSPath(int **edges, int n, int v1, int v2) {
	bool *isVisited = new bool[n]();
	DFS(edges, n, v1, v2, isVisited);
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
	getDFSPath(edges, n, v1, v2);

	return 0;
}