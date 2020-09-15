#include <bits/stdc++.h>

using namespace std;

bool DFS(int **edges, int n, int v1, int v2, vector<int> &dfsPath, bool *isVisited) {
	isVisited[v1] = true;
	dfsPath.push_back(v1);

	if (v1 == v2) {
		return true;
	}

	bool pathFound = false;
	for (int i = 0; i < n; ++i) {
		if (edges[v1][i] and not isVisited[i]) {
			pathFound = DFS(edges, n, i, v2, dfsPath, isVisited);
			if (not pathFound) {
				dfsPath.pop_back();
			} else {
				return pathFound;
			}
		}
	}

	return pathFound;
}

bool getDFSPath(int **edges, int n, int v1, int v2, vector<int> &dfsPath) {
	bool *isVisited = new bool[n]();
	return DFS(edges, n, v1, v2, dfsPath, isVisited);
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
	vector<int> dfsPath;

	if (getDFSPath(edges, n, v1, v2, dfsPath)) {
		for (int i = dfsPath.size()-1; i >= 0; --i) {
			cout << dfsPath[i] << ' ';
		}
	}
	return 0;
}