/**
 *    author:	vulkan
 *    created:	29.03.2020 05:00:32 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define set_arr(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define set_arr2d(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define set_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) arr[i][j][k] = val
#define input_arr(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define input_arr2d(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define input_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) cin >> arr[i][j][k];
#define print_arr(arr,n) for (int i = 0; i < n; ++i) cout << arr[i] << ' '; cout << endl
#define print_arr2d(arr,n,m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << ' '; cout << endl; }

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

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

class segment_tree_t {
	vector<pair<int, int>> tree;
public:
	segment_tree_t(vector<int> &arr);
	void build(vector<int> &arr, int start, int end, int node);
	void update(int start, int end, int node, int idx, int val);
	int query();
};

segment_tree_t::segment_tree_t(vector<int> &arr) {
	int n = arr.size();
	this->tree = vector<pair<int, int>>(4 * n);
	this->build(arr, 0, n - 1, 1);
}

void segment_tree_t::build(vector<int> &arr, int start, int end, int node) {
	if (start == end) {
		this->tree[node] = {arr[start], 0};
		return;
	}

	int mid = (start + end) / 2;
	this->build(arr, start, mid, 2 * node);
	this->build(arr, mid + 1, end, 2 * node + 1);

	pair<int, int> left_data = this->tree[2 * node];
	pair<int, int> right_data = this->tree[2 * node + 1];

	if (left_data.second == 0) {
		this->tree[node] = {left_data.first | right_data.first, 1};
	} else {
		this->tree[node] = {left_data.first ^ right_data.first, 0};
	}
}

void segment_tree_t::update(int start, int end, int node, int idx, int val) {
	if (start == end) {
		this->tree[node] = {val, 0};
		return;
	}

	int mid = (start + end) / 2;
	if (idx <= mid) {
		this->update(start, mid, 2 * node, idx, val);
	} else {
		this->update(mid + 1, end, 2 * node + 1, idx, val);
	}

	pair<int, int> left_data = this->tree[2 * node];
	pair<int, int> right_data = this->tree[2 * node + 1];

	if (left_data.second == 0) {
		this->tree[node] = {left_data.first | right_data.first, 1};
	} else {
		this->tree[node] = {left_data.first ^ right_data.first, 0};
	}
}

int segment_tree_t::query() {
	return this->tree[1].first;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int arr_count = 1;
	while (n--) {
		arr_count *= 2;
	}

	vector<int> arr(arr_count);
	input_arr(arr, arr_count);

	segment_tree_t seg_tree(arr);
	while (m--) {
		int idx, val;
		cin >> idx >> val;
		idx--;
		seg_tree.update(0, arr_count - 1, 1, idx, val);
		cout << seg_tree.query() << endl;
	}

	return 0;
}