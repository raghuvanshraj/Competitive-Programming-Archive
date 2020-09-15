#include <bits/stdc++.h>

using namespace std;

vector<int> BFS(vector<int> *edges, int n, bool *isVisited, int start) {
	queue<int> vertices;
	vertices.push(start);
	isVisited[start] = true;
	vector<int> component;
	while (not vertices.empty()) {
		int currVertex = vertices.front();
		component.push_back(currVertex);
		vertices.pop();
		for (int i = 0; i < edges[currVertex].size(); ++i) {
			if (not isVisited[edges[currVertex][i]]) {
				vertices.push(edges[currVertex][i]);
				isVisited[edges[currVertex][i]] = true;
			}
		}
	}

	return component;
}

vector<vector<int>> findConnectedComponents(vector<int> *edges, int n) {
	vector<vector<int>> components;
	bool *isVisited = new bool[n]();
	for (int i = 0; i < n; ++i) {
		vector<int> currComponent;
		if (not isVisited[i]) {
			currComponent = BFS(edges, n, isVisited, i);
		}

		components.push_back(currComponent);
	}

	return components;
}

bool isPermutationPossible(int *p, int *q, int n, vector<int> *edges) {
	vector<vector<int>> connectedComponents = findConnectedComponents(edges, n);

	for (int i = 0; i < connectedComponents.size(); ++i) {
		vector<int> pp,qq;
		for (int j = 0; j < connectedComponents[i].size(); ++j) {
			pp.push_back(p[connectedComponents[i][j]]);
			qq.push_back(q[connectedComponents[i][j]]);
		}

		sort(pp.begin(), pp.end());
		sort(qq.begin(), qq.end());

		if (pp != qq) {
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n,m;
		cin >> n >> m;
		int *p = new int[n]();
		int *q = new int[n]();

		for (int i = 0; i < n; ++i) {
			cin >> p[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> q[i];
		}

		vector<int> *edges = new vector<int>[n]();
		for (int i = 0; i < m; ++i) {
			int s,e;
			cin >> s >> e;
			edges[s-1].push_back(e-1);
			edges[e-1].push_back(s-1);
		}

		string ans = (isPermutationPossible(p, q, n, edges)) ? "YES" : "NO";
		cout << ans << endl;
	}
	return 0;
}