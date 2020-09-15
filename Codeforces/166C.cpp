/**
 *    author:	vulkan
 *    created:	13.04.2020 01:18:38 PM
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define MOD 1000000007

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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

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

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	INPUT_ARR(arr, n);

	sort(ALL(arr));
	int req_pos = (n + 1) / 2 - 1;
	vector<int>::iterator it = lower_bound(ALL(arr), x);
	vector<int>::iterator jt = upper_bound(ALL(arr), x);
	int ans = -1;
	if (it != arr.end() and * it == x) {
		int i = it - arr.begin(), j = jt - arr.begin();
		if (i <= req_pos and j > req_pos) {
			ans = 0;
		} else {
			if (i < req_pos) {
				int idx = j - 1;
				// cout << idx << endl;
				for (int y = 1; y <= n; ++y) {
					if ((n + y + 1) / 2 - 1 == idx + y) {
						ans = y;
						break;
					}
				}
			} else {
				int idx = i;
				for (int y = 1; y <= n; ++y) {
					if ((n + y + 1) / 2 - 1 == idx) {
						ans = y;
						break;
					}
				}
			}
		}
	} else {
		if (jt == arr.end()) {
			ans = n + 1;
		} else {
			ans = 1;
			int idx = jt - arr.begin();
			req_pos = (n + 2) / 2 - 1;
			if (idx < req_pos) {
				for (int y = 1; y <= n; ++y) {
					if ((n + y + 2) / 2 - 1 == idx + y) {
						ans += y;
						break;
					}
				}
			} else if (idx > req_pos) {
				for (int y = 1; y <= n; ++y) {
					if ((n + y + 2) / 2 - 1 == idx) {
						ans += y;
						break;
					}
				}
			}
		}
	}

	cout << ans;

	return 0;
}