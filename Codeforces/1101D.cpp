/**
 *    author:	vulkan
 *    created:	28.04.2020 11:05:34 PM
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

vector<int> a;
vector<vector<int>> adj_list;
vector<map<int, int>> dp;

void dfs(int u, int p) {
	if (not dp[u].empty()) {
		return;
	}

	if (a[u] != 1) {
		dp[u][a[u]] = 1;
	}
	for (int v : adj_list[u]) {
		if (v != p) {
			dfs(v, u);
			for (pair<int, int> p : dp[v]) {
				int gcd = __gcd(p.first, a[u]);
				if (gcd != 1) {
					dp[u][gcd] = max(dp[u][gcd], p.second + 1);
				}
			}
		}
	}
}

int solve(int u, int p) {
	int ans = 0;
	for (pair<int, int> p : dp[u]) {
		ans = max(ans, p.second);
	}

	for (int v : adj_list[u]) {
		if (v != p) {
			ans = max(ans, solve(v, u));
		}
	}

	int sz = adj_list[u].size();
	for (int i = 0; i <= sz - 1; ++i) {
		for (int j = i + 1; j <= sz - 1; ++j) {
			int x = adj_list[u][i], y = adj_list[u][j];
			if (x != p and y != p) {
				for (pair<int, int> p1 : dp[x]) {
					for (pair<int, int> p2 : dp[y]) {
						int gcd = __gcd(a[u], __gcd(p1.first, p2.first));
						if (gcd != 1) {
							ans = max(ans, p1.second + p2.second + 1);
						}
					}
				}
			}
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	a = vector<int>(n);
	adj_list = vector<vector<int>>(n);
	dp = vector<map<int, int>>(n);
	INPUT_ARR(a, n);
	int m = n - 1;
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	dfs(0, -1);
	cout << solve(0, -1);

	return 0;
}