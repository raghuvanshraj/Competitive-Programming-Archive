/**
 *    author:	vulkan
 *    created:	13.09.2020 01:24:48 PM
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define MOD 1000000007
#define INF 1000000000

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

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

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

template <typename T, typename U>
istream& operator>>(istream &input, pair<T, U> &b) {
	input >> b.first >> b.second;
	return input;
}

template <typename T, typename U>
ostream& operator<<(ostream &output, pair<T, U> &b) {
	output << b.first << ' ' << b.second;
	return output;
}

vector<int> subtree;
vector<int> par;
vector<int> leaf;

void _dfs(vector<vector<int>> &adj_list, int u, int p) {
	subtree[u] = 1;
	par[u] = p;
	for (int v : adj_list[u]) {
		if (v != p) {
			_dfs(adj_list, v, u);
			subtree[u] += subtree[v];
			if (leaf[u] == 0) {
				leaf[u] = leaf[v];
			}
		}
	}

	if (leaf[u] == 0) {
		leaf[u] = u;
	}
}

void dfs(vector<vector<int>> &adj_list, int u) {
	int n = adj_list.size();
	subtree = vector<int>(n + 1);
	par = vector<int>(n + 1);
	leaf = vector<int>(n + 1);
	_dfs(adj_list, u, -1);
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int m = n - 1;
		vector<vector<int>> adj_list(n + 1);
		while (m--) {
			int u, v;
			cin >> u >> v;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		dfs(adj_list, 1);

		vector<vector<int>> cent(n);
		int sm_comp = INF;
		for (int i = 1; i <= n; ++i) {
			int max_comp = -INF;
			int tot_comp = 0;
			for (int j : adj_list[i]) {
				if (j != par[i]) {
					max_comp = max(max_comp, subtree[j]);
					tot_comp += subtree[j];
				}
			}

			int rem_comp = n - tot_comp - 1;
			int curr_comp = max(rem_comp, max_comp);
			cent[curr_comp].push_back(i);
			if (sm_comp > curr_comp) {
				sm_comp = curr_comp;
			}
		}

		if (cent[sm_comp].size() == 1) {
			for (int i = 1; i <= n; ++i) {
				if (not adj_list[i].empty()) {
					cout << i << ' ' << adj_list[i][0] << endl;
					cout << i << ' ' << adj_list[i][0] << endl;
					break;
				}
			}
		} else {
			int u = cent[sm_comp][0];
			int v = cent[sm_comp][1];
			if (v == par[u]) {
				cout << par[leaf[u]] << ' ' << leaf[u] << endl;
				cout << v << ' ' << leaf[u] << endl;
			} else {
				cout << par[leaf[v]] << ' ' << leaf[v] << endl;
				cout << u << ' ' << leaf[v] << endl;
			}
		}
	}

	return 0;
}