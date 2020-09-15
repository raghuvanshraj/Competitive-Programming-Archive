#include <bits/stdc++.h>

using namespace std;

int BFS(vector<int> *edges, int n) {
	queue<int> vertices;
	vertices.push(0);
	bool *isVisited = new bool[n]();
	isVisited[0] = true;
	int *distance = new int[n]();

	while (not vertices.empty()) {
		int currVertex = vertices.front();
		vertices.pop();

		for (int i = 0; i < edges[currVertex].size(); ++i) {
			if (not isVisited[edges[currVertex][i]]) {
				isVisited[edges[currVertex][i]] = true;
				vertices.push(edges[currVertex][i]);
				distance[edges[currVertex][i]] = distance[currVertex] + 1;
			}
		}
	}

	return distance[n-1];
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n,m;
		cin >> n >> m;
		vector<int> *edges = new vector<int>[n]();
		for (int i = 0; i < m; ++i) {
			int s,e;
			cin >> s >> e;
			edges[s-1].push_back(e-1);
			edges[e-1].push_back(s-1);
		}

		int pathLength = BFS(edges, n);
		cout << pathLength << endl;
	}

	return 0;
}