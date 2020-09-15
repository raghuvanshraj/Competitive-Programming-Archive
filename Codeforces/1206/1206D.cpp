/**
 *    author:	vulkan
 *    created:	22.04.2020 05:43:08 PM
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

#define POW2(n) (1LL<<(n))

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

#define MAX_BITS numeric_limits<LL>::digits

vector<int> dec2bin(LL x) {
	vector<int> binary;
	LL j = 1;
	for (int i = 0; i < numeric_limits<LL>::digits; ++i, j <<= 1LL) {
		if (x & j) {
			binary.push_back(1);
		} else {
			binary.push_back(0);
		}
	}

	reverse(ALL(binary));
	return binary;
}

int bfs(vector<set<int>> &adj_list, int s, int e) {
	int n = adj_list.size();
	queue<pair<int, int>> qu;
	vector<bool> visited(n);
	visited[s] = true;
	qu.push({s, 0});
	while (not qu.empty()) {
		pair<int, int> curr = qu.front();
		int x = curr.first, dist = curr.second;
		if (x == e) {
			return dist;
		}
		qu.pop();
		for (int y : adj_list[x]) {
			if (not visited[y]) {
				visited[y] = true;
				qu.push({y, dist + 1});
			}
		}
	}

	return -1;
}

int min_cycle(vector<set<int>> &adj_list, vector<vector<int>> &set_bits) {
	int ans = MAX;
	for (int i = 0; i <= MAX_BITS - 1; ++i) {
		if (set_bits[i].size() <= 1) {
			continue;
		}

		int u = set_bits[i][0], v = set_bits[i][1];
		adj_list[u].erase(v);
		adj_list[v].erase(u);
		int dist = bfs(adj_list, u, v);
		if (dist != -1) {
			ans = min(ans, dist + 1);
		}
		adj_list[u].insert(v);
		adj_list[v].insert(u);
	}

	return (ans == MAX) ? -1 : ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<LL> arr(n);
	INPUT_ARR(arr, n);

	vector<vector<int>> set_bits(MAX_BITS);
	for (int i = 0; i <= n - 1; ++i) {
		vector<int> curr = dec2bin(arr[i]);
		for (int j = 0; j <= MAX_BITS - 1; ++j) {
			if (curr[j]) {
				set_bits[j].push_back(i);
			}
		}
	}

	bool cycle3 = false;
	for (int i = 0; i <= MAX_BITS - 1; ++i) {
		if (set_bits[i].size() > 2) {
			cycle3 = true;
			break;
		}
	}

	if (cycle3) {
		cout << 3;
	} else {
		vector<set<int>> adj_list(n);
		for (int i = 0; i <= MAX_BITS - 1; ++i) {
			if (set_bits[i].size() > 1) {
				int u = set_bits[i][0], v = set_bits[i][1];
				adj_list[u].insert(v);
				adj_list[v].insert(u);
			}
		}

		cout << min_cycle(adj_list, set_bits);
	}

	return 0;
}