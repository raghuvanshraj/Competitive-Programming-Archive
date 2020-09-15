/**
 *    author:	vulkan
 *    created:	21.04.2020 09:21:52 PM
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define MOD 1000000007
#define MAX 1000000000
#define MIN -1000000000

#define SET_ARR(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define SET_ARR2D(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define INPUT_ARR(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define INPUT_ARR2D(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define PRINT_ARR(arr) for (auto x : arr) cout << x << ' '; cout << endl
#define PRINT_ARR2D(arr) for (auto x : arr) { for (auto y : x) cout << y << ' '; cout << endl; }

#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename X, typename T>
auto vectors(X x, T a) {
	return vector<T>(x, a);
}

template <typename X, typename Y, typename Z, typename... Zs>
auto vectors(X x, Y y, Z z, Zs... zs) {
	auto cont = vectors(y, z, zs...);
	return vector<decltype(cont)>(x, cont);
}

template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<U>::value, U>::type,
    typename V,
    typename = typename enable_if<is_arithmetic<V>::value, V>::type
    >
pair<T, U> operator*(const pair<T, U> &b, const V &a) {
	return {a * b.first, a * b.second};
}

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<U>::value, U>::type
    >
istream & operator>>(istream &input, pair<T, U> &b) {
	input >> b.first >> b.second;
	return input;
}

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<U>::value, U>::type
    >
ostream & operator<<(ostream &output, pair<T, U> &b) {
	output << b.first << ' ' << b.second;
	return output;
}

void bfs(vector<vector<int>> &adj_list, vector<ll> &edge_counts, map<pair<int, int>, int> &edge_idx, int u, int v) {
	int n = adj_list.size();
	vector<int> parent(n);
	parent[u] = -1;
	vector<bool> visited(n);
	queue<int> qu;
	qu.push(u);
	visited[u] = true;
	while (not qu.empty()) {
		int curr = qu.front();
		if (curr == v) {
			break;
		}

		qu.pop();
		for (int x : adj_list[curr]) {
			if (not visited[x]) {
				visited[x] = true;
				parent[x] = curr;
				qu.push(x);
			}
		}
	}

	while (parent[v] != -1) {
		edge_counts[edge_idx[ {v, parent[v]}]]++;
		v = parent[v];
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b, c;
		cin >> n >> m >> a >> b >> c;
		a--;
		b--;
		c--;

		vector<int> p(m);
		INPUT_ARR(p, m);
		vector<vector<int>> adj_list(n);
		map<pair<int, int>, int> edge_idx;
		for (int i = 0; i <= m - 1; ++i) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;

			edge_idx[ {u, v}] = i;
			edge_idx[ {v, u}] = i;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		vector<ll> edge_counts(m);
		bfs(adj_list, edge_counts, edge_idx, a, b);
		bfs(adj_list, edge_counts, edge_idx, b, c);

		// PRINT_ARR(edge_counts);
		sort(ALL(edge_counts));
		sort(ALL(p), greater<int>());
		ll ans = 0;
		for (int i = 0; i <= m - 1; ++i) {
			ans += edge_counts[i] * ll(p[i]);
		}

		cout << ans << endl;
	}

	return 0;
}