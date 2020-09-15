#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll BFS(int **edges, int start, bool *isVisited, int n, ll *a) {
	ll coins = 0;
	queue<int> vertices;
	vertices.push(start);
	isVisited[start] = true;
	while (not vertices.empty()) {
		int currVertex = vertices.front();
		coins += a[currVertex];
		vertices.pop();
		for (int i = 0; i < n; ++i) {
			if (edges[currVertex][i] and not isVisited[i]) {
				vertices.push(i);
				isVisited[i] = true;
			}
		}
	}

	return coins;
}

ll maxCoins(int **edges, int n, ll *a) {
	ll coins = INT_MIN;
	bool *isVisited = new bool[n]();
	for (int i = 0; i < n; ++i) {
		if (not isVisited[i]) {
			coins = max(coins, BFS(edges, i, isVisited, n, a));
		}
	}

	return coins;
}


int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n,m;
		cin >> n >> m;
		ll *a = new ll[n]();
		int **edges = new int*[n]();
		for (int i = 0; i < n; ++i) {
			edges[i] = new int[n]();
		}

		for (int i = 0; i < m; ++i) {
			int s,e;
			cin >> s >> e;
			edges[s-1][e-1] = 1;
			edges[e-1][s-1] = 1;
		}

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		// for (int i = 0; i < n; ++i) {
		// 	cout << a[i] << ' ';
		// }

		cout << maxCoins(edges, n, a) << endl;
	}
	return 0;
}