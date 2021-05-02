/**
 *    author:	vulkan
 *    created:	03.08.2020 08:54:40 PM
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

vector<vector<double>> floyd_warshall(vector<tuple<int, int, double>> &edges, int n) {
	auto distance = vectors(n, n, double(-INF));
	for (int i = 0; i <= n - 1; ++i) {
		distance[i][i] = 1;
	}

	for (auto e : edges) {
		int u, v;
		double w;
		tie(u, v, w) = e;
		distance[u][v] = max(distance[u][v], w);
	}

	for (int k = 0; k <= n - 1; ++k) {
		for (int i = 0; i <= n - 1; ++i) {
			for (int j = 0; j <= n - 1; ++j) {
				if (distance[i][k] != -INF and distance[k][j] != -INF) {
					distance[i][j] = max({
						distance[i][j],
						distance[i][k] * distance[k][j]
					});
				}
			}
		}
	}

	return distance;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int count = 1;
	while (cin >> n and n != 0) {
		map<string, int> mp;
		for (int i = 0; i <= n - 1; ++i) {
			string s;
			cin >> s;
			mp[s] = i;
		}

		int m;
		cin >> m;
		vector<tuple<int, int, double>> edges(m);
		for (int i = 0; i <= m - 1; ++i) {
			string s, t;
			double w;
			cin >> s >> w >> t;

			edges[i] = {mp[s], mp[t], w};
		}

		vector<vector<double>> distance = floyd_warshall(edges, n);

		bool flag = false;
		for (int i = 0; i <= n - 1; ++i) {
			if (distance[i][i] > 1) {
				flag = true;
			}
		}

		cout << "Case " << count << ": " << ((flag) ? "Yes" : "No") << endl;
		count++;
	}

	return 0;
}