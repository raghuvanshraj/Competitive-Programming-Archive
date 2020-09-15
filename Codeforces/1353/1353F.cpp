/**
 *    author:	vulkan
 *    created:	01.07.2020 12:21:58 PM
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define MOD 1000000007
#define MAX LLONG_MAX
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

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		auto a = vectors(n, m, LL());
		INPUT_ARR2D(a, n, m);

		LL ans = MAX;
		for (int i = 0; i <= n - 1; ++i) {
			for (int j = 0; j <= m - 1; ++j) {
				auto b = vectors(n, m, LL());
				for (int x = 0; x <= n - 1; ++x) {
					for (int y = 0; y <= m - 1; ++y) {
						if (x == 0 and y == 0) {
							b[0][0] = a[i][j] - i - j;
						} else {
							b[x][y] = b[0][0] + x + y;
						}
					}
				}

				auto dp = vectors(n, m, LL(MAX));
				dp[0][0] = (a[0][0] >= b[0][0]) ? (a[0][0] - b[0][0]) : MAX;
				for (int x = 1; x <= n - 1; ++x) {
					if (dp[x - 1][0] != MAX and a[x][0] >= b[x][0]) {
						dp[x][0] = dp[x - 1][0] + a[x][0] - b[x][0];
					}
				}
				for (int y = 1; y <= m - 1; ++y) {
					if (dp[0][y - 1] != MAX and a[0][y] >= b[0][y]) {
						dp[0][y] = dp[0][y - 1] + a[0][y] - b[0][y];
					}
				}

				for (int x = 1; x <= n - 1; ++x) {
					for (int y = 1; y <= m - 1; ++y) {
						if (a[x][y] >= b[x][y]) {
							if (dp[x - 1][y] != MAX) {
								dp[x][y] = min(dp[x - 1][y] + a[x][y] - b[x][y], dp[x][y]);
							}
							if (dp[x][y - 1] != MAX) {
								dp[x][y] = min(dp[x][y - 1] + a[x][y] - b[x][y], dp[x][y]);
							}
						}
					}
				}

				ans = min(ans, dp[n - 1][m - 1]);
			}
		}

		cout << ans << endl;
	}

	return 0;
}