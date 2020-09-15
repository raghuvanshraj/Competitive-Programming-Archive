/**
 *    author:	vulkan
 *    created:	05.05.2020 08:40:41 PM
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

LL compute(LL x, LL y, LL z) {
	return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int nr, ng, nb;
		cin >> nr >> ng >> nb;
		vector<LL> r(nr), g(ng), b(nb);
		INPUT_ARR(r, nr);
		INPUT_ARR(g, ng);
		INPUT_ARR(b, nb);

		sort(ALL(r));
		sort(ALL(g));
		sort(ALL(b));

		LL ans = LLONG_MAX;
		for (LL curr2 : g) {
			auto it1 = lower_bound(ALL(r), curr2);
			if (it1 == r.end() or (*it1 > curr2 and it1 != r.begin())) {
				it1--;
			}

			auto it2 = lower_bound(ALL(b), curr2);
			if (it2 == b.end()) {
				continue;
			}

			LL curr1 = *it1, curr3 = *it2;
			ans = min(ans, compute(curr1, curr2, curr3));
		}

		for (LL curr2 : g) {
			auto it1 = lower_bound(ALL(b), curr2);
			if (it1 == b.end() or (*it1 > curr2 and it1 != b.begin())) {
				it1--;
			}

			auto it2 = lower_bound(ALL(r), curr2);
			if (it2 == r.end()) {
				continue;
			}

			LL curr1 = *it1, curr3 = *it2;
			ans = min(ans, compute(curr1, curr2, curr3));
		}

		for (LL curr2 : r) {
			auto it1 = lower_bound(ALL(b), curr2);
			if (it1 == b.end() or (*it1 > curr2 and it1 != b.begin())) {
				it1--;
			}

			auto it2 = lower_bound(ALL(g), curr2);
			if (it2 == g.end()) {
				continue;
			}

			LL curr1 = *it1, curr3 = *it2;
			ans = min(ans, compute(curr1, curr2, curr3));
		}

		for (LL curr2 : r) {
			auto it1 = lower_bound(ALL(g), curr2);
			if (it1 == g.end() or (*it1 > curr2 and it1 != g.begin())) {
				it1--;
			}

			auto it2 = lower_bound(ALL(b), curr2);
			if (it2 == b.end()) {
				continue;
			}

			LL curr1 = *it1, curr3 = *it2;
			ans = min(ans, compute(curr1, curr2, curr3));
		}

		for (LL curr2 : b) {
			auto it1 = lower_bound(ALL(r), curr2);
			if (it1 == r.end() or (*it1 > curr2 and it1 != r.begin())) {
				it1--;
			}

			auto it2 = lower_bound(ALL(g), curr2);
			if (it2 == g.end()) {
				continue;
			}

			LL curr1 = *it1, curr3 = *it2;
			ans = min(ans, compute(curr1, curr2, curr3));
		}

		for (LL curr2 : b) {
			auto it1 = lower_bound(ALL(g), curr2);
			if (it1 == g.end() or (*it1 > curr2 and it1 != g.begin())) {
				it1--;
			}

			auto it2 = lower_bound(ALL(r), curr2);
			if (it2 == r.end()) {
				continue;
			}

			LL curr1 = *it1, curr3 = *it2;
			ans = min(ans, compute(curr1, curr2, curr3));
		}

		cout << ans << endl;
	}

	return 0;
}