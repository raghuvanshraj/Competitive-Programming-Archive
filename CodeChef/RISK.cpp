/**
 *    author:	vulkan
 *    created:	25.03.2022 06:48:53 PM
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

bool is_valid(int i, int j, int n, int m) {
	return (
	           (i >= 0 and i < n) and
	           (j >= 0 and j < m)
	       );
}

int bfs(vector<string> &matrix, vector<vector<bool>> &visited, int i, int j) {
	int n = matrix.size();
	int m = matrix[0].size();
	queue<pair<int, int>> qu;
	qu.push({i, j});
	visited[i][j] = true;
	int cnt = 0;
	vector<pair<int, int>> adj = {
		{1, 0},
		{0, 1},
		{ -1, 0},
		{0, -1}
	};
	while (not qu.empty()) {
		auto[x, y] = qu.front();
		cnt++;
		qu.pop();
		for (auto[i, j] : adj) {
			int xi = x + i;
			int yj = y + j;
			if (is_valid(xi, yj, n, m) and matrix[xi][yj] == '1' and not visited[xi][yj]) {
				visited[xi][yj] = true;
				qu.push({xi, yj});
			}
		}
	}

	return cnt;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<string> matrix(n);
		auto visited = vectors(n, m, bool());
		for (int i = 0; i <= n - 1; ++i) {
			cin >> matrix[i];
		}

		vector<int> cnts;
		for (int i = 0; i <= n - 1; ++i) {
			for (int j = 0; j <= m - 1; ++j) {
				if (matrix[i][j] == '1' and not visited[i][j]) {
					cnts.push_back(bfs(matrix, visited, i, j));
				}
			}
		}

		sort(cnts.begin(), cnts.end(), greater<int>());
		int ans = 0;
		int sz = cnts.size();
		for (int i = 1; i <= sz - 1; i += 2) {
			ans += cnts[i];
		}

		cout << ans << endl;
	}

	return 0;
}