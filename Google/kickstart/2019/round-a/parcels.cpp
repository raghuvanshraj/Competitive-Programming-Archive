/**
 *    author:	vulkan
 *    created:	04.11.2019 03:38:19 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define pb push_back
#define all(v) v.begin(), v.end()
#define deci(a,n) int *a = new int[n]()
#define decl(a,n) long *a = new long[n]()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

int** get_shortest_distances(vector<pair<int, int>> sources, int r, int c) {
	int n = sources.size();
	int **distances = new int*[r]();
	bool **is_visited = new bool*[r]();
	for (int i = 0; i < r; ++i) {
		distances[i] = new int[c]();
		is_visited[i] = new bool[c]();
		for (int j = 0; j < c; ++j) {
			distances[i][j] = INT_MAX;
		}
	}

	queue<pair<int, int>> qu;
	for (int i = 0; i < n; ++i) {
		qu.push(sources[i]);
		is_visited[sources[i].first][sources[i].second] = true;
		distances[sources[i].first][sources[i].second] = 0;
	}

	while (not qu.empty()) {
		pair<int, int> curr_vertex = qu.front();
		qu.pop();
		int x = curr_vertex.first, y = curr_vertex.second;
		pair<int, int> adj_vertices[] = {
			{x + 1, y},
			{x - 1, y},
			{x, y + 1},
			{x, y - 1}
		};

		for (int i = 0; i < 4; ++i) {
			int curr_x = adj_vertices[i].first, curr_y = adj_vertices[i].second;
			if (curr_x >= 0 and curr_x < r and curr_y >= 0 and curr_y < c and not is_visited[curr_x][curr_y]) {
				is_visited[curr_x][curr_y] = true;
				qu.push(adj_vertices[i]);
				distances[curr_x][curr_y] = min(distances[curr_x][curr_y], distances[x][y] + 1);
			}
		}
	}

	return distances;
}

bool is_possible(int **distances, int curr_dist, int r, int c) {
	int xplusy_max = INT_MIN, xplusy_min = INT_MAX;
	int xdiffy_max = INT_MIN, xdiffy_min = INT_MAX;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (distances[i][j] > curr_dist) {
				xplusy_max = max(xplusy_max, i + j);
				xplusy_min = min(xplusy_min, i + j);
				xdiffy_max = max(xdiffy_max, i - j);
				xdiffy_min = min(xdiffy_min, i - j);
			}
		}
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			pii top = {i - curr_dist, j};
			pii bottom = {i + curr_dist, j};

			if (xdiffy_max <= bottom.ff - bottom.ss and
			        xdiffy_min >= top.ff - top.ss and
			        xplusy_max <= bottom.ff + bottom.ss and
			        xplusy_min >= top.ff + top.ss) {

				return true;
			}
		}
	}

	return false;
}

int parcels(string graph[], int r, int c) {
	vector<pair<int, int>> sources;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (graph[i][j] == '1') {
				sources.push_back({i, j});
			}
		}
	}

	int **distances = get_shortest_distances(sources, r, c);

	int low = 0, high = r + c;
	int ans = high;
	while (low < high) {
		int mid = (low + high) / 2;
		if (is_possible(distances, mid, r, c)) {
			high = mid;
			ans = mid;
		} else {
			low = mid + 1;
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int r, c;
		cin >> r >> c;
		string graph[r];
		for (int i = 0; i < r; ++i) {
			cin >> graph[i];
		}

		int ans = parcels(graph, r, c);

		cout << "Case #" << t + 1 << ": " << ans << endl;
	}

	return 0;
}
