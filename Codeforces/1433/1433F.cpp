/**
 *    author:	vulkan
 *    created:	14.11.2020 11:58:36 AM
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

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	if (m == 1) {
		cout << 0;
		return 0;
	}

	auto arr = vectors(n, m, int());
	INPUT_ARR2D(arr, n, m);
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 0; j <= m - 1; ++j) {
			g[i][j][0][0] = 0;
		}
	}
	for (int i = 0; i <= n - 1; ++i) {
		g[i][0][1][arr[i][0] % k] = arr[i][0];
	}
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = 1; j <= m - 1; ++j) {
			for (int x = 1; x <= m / 2; ++x) {
				for (int r = 0; r <= k - 1; ++r) {
					g[i][j][x][r] = max(g[i][j - 1][x - 1][(r - (arr[i][j] % k) + k) % k] + arr[i][j], g[i][j - 1][x][r]);
				}
			}
		}
	}

	for (int i = 0; i <= n - 1; ++i) {
		for (int r = 0; r <= k - 1; ++r) {
			for (int x = 1; x <= m / 2; ++x) {
				g[i][m - 1][x][r] = max(g[i][m - 1][x - 1][r], g[i][m - 1][x][r]);
			}
		}
	}

	auto f = vectors(n, k, int(-INF));
	for (int r = 0; r <= k - 1; ++r) {
		f[0][r] = g[0][m - 1][m / 2][r];
	}
	for (int i = 1; i <= n - 1; ++i) {
		for (int r = 0; r <= k - 1; ++r) {
			for (int pr = 0; pr <= k - 1; ++pr) {
				f[i][r] = max(g[i][m - 1][m / 2][pr] + f[i - 1][(r - pr + k) % k], f[i][r]);
			}
		}
	}


	cout << f[n - 1][0];

	return 0;
}