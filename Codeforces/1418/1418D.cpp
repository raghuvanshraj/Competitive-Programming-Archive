/**
 *    author:	vulkan
 *    created:	23.09.2020 10:56:11 AM
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

	int n, q;
	cin >> n >> q;
	indexed_set<int> s;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		int x;
		cin >> x;
		s.insert(x);
		arr[i] = x;
	}
	map<int, int> diff;
	sort(ALL(arr));
	for (int i = 1; i <= n - 1; ++i) {
		diff[arr[i] - arr[i - 1]]++;
	}

	if (not diff.empty()) {
		auto it = diff.end();
		int total_diff = arr[n - 1] - arr[0];
		it--;
		cout << total_diff - it->first << endl;
	} else {
		cout << 0 << endl;
	}

	while (q--) {
		int t, x;
		cin >> t >> x;
		if (t == 0) {
			int idx = s.order_of_key(x);
			if (idx > 0) {
				int curr = *(s.find_by_order(idx)) - *(s.find_by_order(idx - 1));
				diff[curr]--;
				if (diff[curr] == 0) {
					diff.erase(curr);
				}
			}
			if (idx < s.size() - 1) {
				int curr = *(s.find_by_order(idx + 1)) - *(s.find_by_order(idx));
				diff[curr]--;
				if (diff[curr] == 0) {
					diff.erase(curr);
				}
			}
			if (idx > 0 and idx < s.size() - 1) {
				int curr = *(s.find_by_order(idx + 1)) - *(s.find_by_order(idx - 1));
				diff[curr]++;
			}
			s.erase(x);
		} else if (t == 1) {
			s.insert(x);
			int idx = s.order_of_key(x);
			if (idx > 0 and idx < s.size() - 1) {
				int curr = *(s.find_by_order(idx + 1)) - *(s.find_by_order(idx - 1));
				diff[curr]--;
				if (diff[curr] == 0) {
					diff.erase(curr);
				}
			}
			if (idx > 0) {
				int curr = x - *(s.find_by_order(idx - 1));
				diff[curr]++;
			}
			if (idx < s.size() - 1) {
				int curr = *(s.find_by_order(idx + 1)) - x;
				diff[curr]++;
			}
		}

		if (s.size() <= 2) {
			cout << 0 << endl;
			continue;
		}
		int total_diff = *(s.find_by_order(s.size() - 1)) - *(s.find_by_order(0));
		auto it = diff.end();
		it--;
		cout << total_diff - it->first << endl;
	}

	return 0;
}