/**
 *    author:	vulkan
 *    created:	29.08.2020 04:27:42 PM
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

void dfs(vector<vector<int>> &adj_list, int u, int p) {
	subtree[u] = 1;
	for (int v : adj_list[u]) {
		if (v != p) {
			dfs(adj_list, v, u);
			subtree[u] += subtree[v];
		}
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		auto adj_list = vectors(n, vector<int>());
		for (int i = 0; i <= n - 2; ++i) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		int m;
		cin >> m;
		vector<int> p(m);
		INPUT_ARR(p, m);

		sort(ALL(p));

		vector<LL> p_mod(n - 1);
		if (m >= n - 1) {
			for (int i = 0; i <= n - 3; ++i) {
				p_mod[i] = p[i];
			}

			LL last = 1;
			for (int i = n - 2; i <= m - 1; ++i) {
				last *= p[i];
				last %= MOD;
			}

			p_mod[n - 2] = last;
		} else {
			for (int i = 0; i <= n - m - 2; ++i) {
				p_mod[i] = 1;
			}
			for (int i = n - m - 1; i <= n - 2; ++i) {
				p_mod[i] = p[i - n + m + 1];
			}
		}

		vector<LL> cnt(n - 1);
		subtree = vector<int>(n);
		dfs(adj_list, 0, -1);
		for (int i = 1; i <= n - 1; ++i) {
			cnt[i - 1] = subtree[i] * LL(n - subtree[i]);
		}

		sort(ALL(cnt));

		LL ans = 0;
		for (int i = 0; i <= n - 2; ++i) {
			ans = (ans + (cnt[i] * p_mod[i]) % MOD) % MOD;
		}

		cout << ans << endl;
	}

	return 0;
}