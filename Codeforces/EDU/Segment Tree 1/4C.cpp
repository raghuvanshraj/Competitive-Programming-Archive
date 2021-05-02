/**
 *    author:	vulkan
 *    created:	07.09.2020 03:55:57 PM
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

class segment_tree_t {
	int n, v;
	vector<int> tree;
public:
	segment_tree_t(vector<int> &arr, int v);
	void update(int x, int v);
	int query(int l, int r);
};

segment_tree_t::segment_tree_t(vector<int> &arr, int v) {
	int n = arr.size();
	this->n = 1;
	this->v = v;
	while (this->n < n) {
		this->n *= 2;
	}
	this->tree = vector<int>(2 * this->n);
	for (int i = 0; i <= n - 1; ++i) {
		this->update(i, arr[i]);
	}
}

void segment_tree_t::update(int x, int v) {
	x += this->n;
	this->tree[x] = (v > this->v);
	for (x /= 2; x >= 1; x /= 2) {
		this->tree[x] = this->tree[2 * x] + this->tree[2 * x + 1];
	}
}

int segment_tree_t::query(int l, int r) {
	l += this->n, r += this->n;
	int ans = 0;
	while (l <= r) {
		if (l % 2 == 1) {
			ans += this->tree[l];
			l++;
		}
		if (r % 2 == 0) {
			ans += this->tree[r];
			r--;
		}

		l /= 2, r /= 2;
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	INPUT_ARR(arr, n);
	vector<segment_tree_t> seg_tree;
	for (int i = 0; i <= 40; ++i) {
		seg_tree.push_back(segment_tree_t(arr, i));
	}

	while (m--) {
		int t;
		cin >> t;
		if (t == 1) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			int ans = 0;
			for (int i = x; i <= y; ++i) {
				ans += seg_tree[arr[i]].query(x, i);
			}
			cout << ans << endl;
		} else {
			int x, y;
			cin >> x >> y;
			x--;
			for (int i = 0; i <= 40; ++i) {
				seg_tree[i].update(x, y);
			}
			arr[x] = y;
		}
	}

	return 0;
}