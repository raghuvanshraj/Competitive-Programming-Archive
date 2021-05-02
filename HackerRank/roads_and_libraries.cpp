/**
 *    author:	vulkan
 *    created:	26.03.2020 09:55:47 AM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define set_arr(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define set_arr2d(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define set_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) arr[i][j][k] = val
#define input_arr(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define input_arr2d(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define input_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) cin >> arr[i][j][k];
#define print_arr(arr,n) for (int i = 0; i < n; ++i) cout << arr[i] << ' '; cout << endl
#define print_arr2d(arr,n,m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << ' '; cout << endl; }

#define all(v) v.begin(), v.end()
#define dec(a,t,n) t *a = new t[n]()
#define dec2d(a,t,n,m) t **a = new t*[n](); for (int i = 0; i < n; ++i) a[i] = new t[m]()

using namespace std;

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
using max_heap = priority_queue<T>;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<U>::value, U>::type
    >
pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {
	return {a.first + b.first, a.second + b.second};
}

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<U>::value, U>::type
    >
pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) {
	return {a.first - b.first, a.second - b.second};
}

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<U>::value, U>::type,
    typename V,
    typename = typename enable_if<is_arithmetic<V>::value, V>::type
    >
pair<T, U> operator*(const V &a, const pair<T, U> &b) {
	return {a * b.first, a * b.second};
}

void bfs(vector<vector<int>> &adj_list, vector<bool> &visited, int u, int &count) {
	queue<int> qu;
	qu.push(u);
	visited[u] = true;
	while (not qu.empty()) {
		int curr = qu.front();
		count++;
		qu.pop();
		for (int v : adj_list[curr]) {
			if (not visited[v]) {
				qu.push(v);
				visited[v] = true;
			}
		}
	}
}

vector<int> get_connected_comp(vector<vector<int>> &adj_list) {
	int n = adj_list.size();
	vector<bool> visited(n);
	vector<int> components;
	for (int u = 0; u < n; ++u) {
		if (not visited[u]) {
			int count = 0;
			bfs(adj_list, visited, u, count);
			components.push_back(count);
		}
	}

	return components;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	while (q--) {
		int n, m, clib, croad;
		cin >> n >> m >> clib >> croad;
		vector<vector<int>> adj_list(n);
		while (m--) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;

			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		vector<int> components = get_connected_comp(adj_list);
		ll cost = 0;
		for (int comp : components) {
			if (clib >= croad) {
				cost += clib + ll(comp - 1) * croad;
			} else {
				cost += ll(comp) * clib;
			}
		}

		cout << cost << endl;
	}

	return 0;
}