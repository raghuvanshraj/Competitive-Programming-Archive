/**
 *    author:	vulkan
 *    created:	23.08.2020 01:03:44 AM
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

struct segment_tree_node_t {
	LL prefix;
	LL suffix;
	LL sum;
	LL max_segment;
};

class segment_tree_t {
	int n;
	vector<segment_tree_node_t> tree;
public:
	segment_tree_t(vector<int> &arr);
	void update(int x, int v);
	LL query();
};

segment_tree_t::segment_tree_t(vector<int> &arr) {
	int n = arr.size();
	int d = 0;
	bool is_power = true;
	int x = n;
	while (x) {
		if ((x & 1) and x != 1) {
			is_power = false;
		}
		x /= 2;
		d++;
	}
	d += is_power;
	this->n = (1 << d);
	this->tree = vector<segment_tree_node_t>(2 * this->n);
	for (int i = 0; i <= n - 1; ++i) {
		this->update(i, arr[i]);
	}
}

void segment_tree_t::update(int x, int v) {
	x += this->n;
	this->tree[x] = {
		max(v, 0),
		max(v, 0),
		v,
		max(v, 0)
	};
	for (x /= 2; x >= 1; x /= 2) {
		this->tree[x].sum = this->tree[2 * x].sum + this->tree[2 * x + 1].sum;
		this->tree[x].prefix = max(this->tree[2 * x].prefix, this->tree[2 * x].sum + this->tree[2 * x + 1].prefix);
		this->tree[x].suffix = max(this->tree[2 * x + 1].suffix, this->tree[2 * x + 1].sum + this->tree[2 * x].suffix);
		this->tree[x].max_segment = max({
			this->tree[2 * x].max_segment,
			this->tree[2 * x + 1].max_segment,
			this->tree[2 * x].suffix + this->tree[2 * x + 1].prefix
		});
	}
}

LL segment_tree_t::query() {
	return this->tree[1].max_segment;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	INPUT_ARR(arr, n);

	segment_tree_t seg_tree(arr);
	cout << seg_tree.query() << endl;
	while (m--) {
		int i, v;
		cin >> i >> v;
		seg_tree.update(i, v);
		cout << seg_tree.query() << endl;
	}

	return 0;
}