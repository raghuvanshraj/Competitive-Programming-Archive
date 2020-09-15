/**
 *    author:	vulkan
 *    created:	02.04.2020 07:58:43 PM
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define MOD 1000000007

#define SET_ARR(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define SET_ARR2D(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define INPUT_ARR(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define INPUT_ARR2D(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define PRINT_ARR(arr,n) for (int i = 0; i < n; ++i) cout << arr[i] << ' '; cout << endl
#define PRINT_ARR2D(arr,n,m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << ' '; cout << endl; }

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

bool get_pair(ll x, ll s, vector<ll> &ans) {
	if (x > s or (s - x) % 2 != 0) {
		return false;
	}

	ll a = (s - x) / 2;
	ll m = 1;
	ll var_a = 0, var_b = 0;
	while (x or a) {
		int x_bit = (x & 1), a_bit = (a & 1);
		if (x_bit == 1 and a_bit == 1) {
			return false;
		} else if (x_bit == 1 and a_bit == 0) {
			var_a += m;
		} else if (x_bit == 0 and a_bit == 1) {
			var_a += m;
			var_b += m;
		}

		x /= 2LL;
		a /= 2LL;

		m *= 2LL;
	}

	if (var_a) {
		ans.push_back(var_a);
	}
	if (var_b) {
		ans.push_back(var_b);
	}

	return true;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll u, v;
	cin >> u >> v;

	vector<ll> ans;
	bool possible = get_pair(u, v, ans);
	if (not possible) {
		ans.push_back(u);
		possible = get_pair(0, v - u, ans);
	}

	if (not possible) {
		cout << "-1";
	} else {
		cout << ans.size() << endl;
		PRINT_ARR(ans, ans.size());
	}

	return 0;
}