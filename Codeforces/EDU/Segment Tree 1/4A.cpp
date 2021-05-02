/**
 *    author:	vulkan
 *    created:	07.09.2020 10:05:14 AM
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
	int n;
	vector<LL> tree;
public:
	segment_tree_t(vector<LL> &arr);
	void update(int x, LL v);
	LL query(int l, int r);
};

segment_tree_t::segment_tree_t(vector<LL> &arr) {
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
	this->tree = vector<LL>(2 * this->n);
	for (int i = 0; i <= n - 1; ++i) {
		this->update(i, arr[i]);
	}
}

void segment_tree_t::update(int x, LL v) {
	x += this->n;
	this->tree[x] = v;
	for (x /= 2; x >= 1; x /= 2) {
		this->tree[x] = this->tree[2 * x] + this->tree[2 * x + 1];
	}
}

LL segment_tree_t::query(int l, int r) {
	l += this->n, r += this->n;
	LL ans = 0;
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

	int n;
	cin >> n;
	vector<LL> arr(n);
	INPUT_ARR(arr, n);

	for (int i = 0; i <= n - 1; ++i) {
		if (i & 1) {
			arr[i] *= -1;
		}
	}

	segment_tree_t seg_tree(arr);
	int m;
	cin >> m;
	while (m--) {
		int t;
		cin >> t;
		if (t == 0) {
			LL i, j;
			cin >> i >> j;
			i--;
			if (i & 1) {
				j *= -1;
			}
			seg_tree.update(i, j);
		} else {
			int l, r;
			cin >> l >> r;
			l--, r--;
			LL ans = seg_tree.query(l, r);
			if (l & 1) {
				ans *= -1;
			}
			cout << ans << endl;
		}
	}

	return 0;
}