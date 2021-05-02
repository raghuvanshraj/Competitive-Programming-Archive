/**
 *    author:	vulkan
 *    created:	08.12.2020 06:13:44 PM
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

vector<int> dfs(stack<int> &st, vector<vector<int>> &adj_list, vector<bool> &vis, int u, int p = -1) {
	if (vis[u]) {
		vector<int> cycle;
		cycle.push_back(u);
		while (st.top() != u) {
			cycle.push_back(st.top());
			st.pop();
		}

		return cycle;
	}

	st.push(u);
	vis[u] = true;

	for (int v : adj_list[u]) {
		if (v != p) {
			vector<int> cycle = dfs(st, adj_list, vis, v, u);
			if (not cycle.empty()) {
				return cycle;
			}
		}
	}

	while (st.top() != u) {
		st.pop();
	}
	st.pop();

	return {};
}

void dfs(vector<vector<int>> &adj_list, int u, int p, int &cnt) {
	cnt++;
	for (int v : adj_list[u]) {
		if (v != p) {
			dfs(adj_list, v, u, cnt);
		}
	}
}

vector<int> detect_cycle(vector<vector<int>> &adj_list, int n) {
	stack<int> st;
	vector<bool> vis(n);
	return dfs(st, adj_list, vis, 0);
}

LL nC2(int n) {
	return (n * LL(n - 1)) / 2;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> adj_list(n);
		int m = n;
		while (m--) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		vector<int> cycle = detect_cycle(adj_list, n);

		vector<bool> in_cycle(n);
		for (int x : cycle) {
			in_cycle[x] = true;
		}

		vector<int> nodes(n, 1);
		for (int u : cycle) {
			for (int v : adj_list[u]) {
				if (not in_cycle[v]) {
					int cnt = 0;
					dfs(adj_list, v, u, cnt);
					nodes[u] += cnt;
				}
			}
		}

		LL ans = n * LL(n - 1);
		for (int x : nodes) {
			ans -= nC2(x);
		}

		cout << ans << endl;
	}

	return 0;
}