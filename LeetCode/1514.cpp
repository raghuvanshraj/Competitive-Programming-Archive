/**
 *    author:	vulkan
 *    created:	13.08.2020 09:58:18 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<double> dijkstra(vector<vector<pair<int, double>>> &adj_list, int u) {
	int n = adj_list.size();
	vector<double> probs(n, 0);
	probs[u] = 1;
	priority_queue<pair<double, int>> qu;
	qu.push({1, u});
	vector<bool> processed(n);
	while (not qu.empty()) {
		int x = qu.top().second;
		qu.pop();
		if (not processed[x]) {
			processed[x] = true;
			for (auto edge : adj_list[x]) {
				int y = edge.first;
				double wt = edge.second;
				if (probs[y] < probs[x] * wt) {
					probs[y] = probs[x] * wt;
					qu.push({probs[y], y});
				}
			}
		}
	}

	return probs;
}

double maxProbability(int n, vector<vector<int>> &edges, vector<double> &probs, int s, int e) {
	int m = edges.size();
	vector<vector<pair<int, double>>> adj_list(n);
	for (int i = 0; i <= m - 1; ++i) {
		adj_list[edges[i][0]].push_back({edges[i][1], probs[i]});
		adj_list[edges[i][1]].push_back({edges[i][0], probs[i]});
	}

	return dijkstra(adj_list, s)[e];
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> edges(m, vector<int>(2));
	vector<double> probs(m);
	for (int i = 0; i <= m - 1; ++i) {
		cin >> edges[i][0] >> edges[i][1];
	}
	for (int i = 0; i <= m - 1; ++i) {
		cin >> probs[i];
	}
	int s, e;
	cin >> s >> e;

	cout << maxProbability(n, edges, probs, s, e);

	return 0;
}