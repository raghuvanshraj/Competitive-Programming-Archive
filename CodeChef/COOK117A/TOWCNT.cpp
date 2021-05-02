/**
 *    author:	vulkan
 *    created:	20.04.2020 11:07:45 PM
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

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

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

struct obs_t {
	int t;
	ll x;
	ll a;
};

ll lcm(ll a, ll b) {
	return (a * b) / __gcd(a, b);
}

pair<ll, ll> min(pair<ll, ll> &a, pair<ll, ll> &b) {
	ll l = lcm(a.second, b.second);
	ll b_prime = l / b.second;
	ll a_prime = l / a.second;
	pair<ll, ll> new_a = a * a_prime;
	pair<ll, ll> new_b = b * b_prime;
	if (new_a.first < new_b.first) {
		return a;
	} else {
		return b;
	}
}

pair<ll, ll> max(pair<ll, ll> &a, pair<ll, ll> &b) {
	ll l = lcm(a.second, b.second);
	ll b_prime = l / b.second;
	ll a_prime = l / a.second;
	pair<ll, ll> new_a = a * a_prime;
	pair<ll, ll> new_b = b * b_prime;
	if (new_a.first > new_b.first) {
		return a;
	} else {
		return b;
	}
}

bool in_range(pair<ll, ll> curr_slope, pair<ll, ll> min_slope, pair<ll, ll> max_slope) {
	ll l = lcm(curr_slope.second, lcm(min_slope.second, max_slope.second));
	ll curr_prime = l / curr_slope.second;
	ll max_prime = l / max_slope.second;
	ll min_prime = l / min_slope.second;
	max_slope = max_slope * max_prime;
	min_slope = min_slope * min_prime;
	curr_slope = curr_slope * curr_prime;
	if (curr_slope.first >= min_slope.first and curr_slope.first <= max_slope.first) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int h, n;
		cin >> h >> n;
		vector<obs_t> arr(n);
		for (int i = 0; i <= n - 1; ++i) {
			cin >> arr[i].t >> arr[i].x >> arr[i].a;
		}

		vector<int> ans(n);
		for (int i = 0; i <= n - 1; ++i) {
			pair<ll, ll> min_slope = {MIN, 1LL}, max_slope = {MAX, 1LL};
			for (int j = i + 1; j <= n - 1; ++j) {
				pair<ll, ll> curr_slope = {arr[j].a - arr[i].a, arr[j].x - arr[i].x};
				if (curr_slope.second < 0) {
					curr_slope = curr_slope * -1;
				}

				if (in_range(curr_slope, min_slope, max_slope)) {
					ans[i]++;
					ans[j]++;
				}

				if (arr[j].t) {
					max_slope = min(max_slope, curr_slope);
				} else {
					min_slope = max(min_slope, curr_slope);
				}
			}
		}

		PRINT_ARR(ans);
	}

	return 0;
}