/**
 *    author:	vulkan
 *    created:	09.09.2020 10:26:28 AM
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define MOD 1000000007
#define INF 1000000000000000000

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

class segment_tree_t {
	int n;
	vector<pair<LL, LL>> tree;

	void _update(int l, int r, LL v, int x, int lx, int rx);
	LL _query(int l, int r, int x, int lx, int rx);
public:
	segment_tree_t(int n);
	void update(int l, int r, LL v);
	LL query(int l, int r);
};

segment_tree_t::segment_tree_t(int n) {
	this->n = 1;
	while (this->n < n) {
		this->n *= 2;
	}
	this->tree = vector<pair<LL, LL>>(2 * this->n);
}

void segment_tree_t::_update(int l, int r, LL v, int x, int lx, int rx) {
	if (rx < l or lx > r) {
		return;
	} else if (lx >= l and rx <= r) {
		this->tree[x].first += v;
		this->tree[x].second += v;
		return;
	}

	int mx = (lx + rx) / 2;
	this->_update(l, r, v, 2 * x, lx, mx);
	this->_update(l, r, v, 2 * x + 1, mx + 1, rx);

	this->tree[x].second = min(this->tree[2 * x].second, this->tree[2 * x + 1].second) + this->tree[x].first;
}

void segment_tree_t::update(int l, int r, LL v) {
	this->_update(l, r, v, 1, 0, this->n - 1);
}

LL segment_tree_t::_query(int l, int r, int x, int lx, int rx) {
	if (rx < l or lx > r) {
		return INF;
	} else if (lx >= l and rx <= r) {
		return this->tree[x].second;
	}

	int mx = (lx + rx) / 2;
	return min({
		this->_query(l, r, 2 * x, lx, mx),
		this->_query(l, r, 2 * x + 1, mx + 1, rx)
	}) + this->tree[x].first;
}

LL segment_tree_t::query(int l, int r) {
	return this->_query(l, r, 1, 0, this->n - 1);
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	segment_tree_t seg_tree(n);
	while (m--) {
		int t;
		cin >> t;
		if (t == 1) {
			LL l, r, v;
			cin >> l >> r >> v;
			r--;
			seg_tree.update(l, r, v);
		} else {
			int l, r;
			cin >> l >> r;
			r--;
			cout << seg_tree.query(l, r) << endl;
		}
	}

	return 0;
}