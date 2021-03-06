/**
 *    author:	vulkan
 *    created:	16.08.2020 11:06:00 AM
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

void counting_sort(vector<int> &p, vector<int> &c) {
	int n = p.size();
	vector<int> cnt(n);
	for (int i = 0; i <= n - 1; ++i) {
		cnt[c[i]]++;
	}

	vector<int> pos(n);
	for (int i = 1; i <= n - 1; ++i) {
		pos[i] = pos[i - 1] + cnt[i - 1];
	}

	vector<int> p_new(n);
	for (int i = 0; i <= n - 1; ++i) {
		int x = c[p[i]];
		p_new[pos[x]] = p[i];
		pos[x]++;
	}

	p = p_new;
}

vector<int> build_suffix(string &s) {
	s = s + "#";
	int n = s.size();
	vector<pair<char, int>> a(n);
	for (int i = 0; i <= n - 1; ++i) {
		a[i] = {s[i], i};
	}

	sort(ALL(a));

	vector<int> p(n), c(n);
	for (int i = 0; i <= n - 1; ++i) {
		p[i] = a[i].second;
	}

	c[p[0]] = 0;
	for (int i = 1; i <= n - 1; ++i) {
		if (a[i].first == a[i - 1].first) {
			c[p[i]] = c[p[i - 1]];
		} else {
			c[p[i]] = c[p[i - 1]] + 1;
		}
	}

	int k = 0;
	while ((1 << k) < n) {
		SET_ARR(p, n, (p[i] - (1 << k) + n) % n);

		counting_sort(p, c);

		vector<int> c_new(n);
		c_new[p[0]] = 0;
		for (int i = 1; i <= n - 1; ++i) {
			pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
			pair<int, int> curr = {c[p[i]], c[(p[i] + (1 << k)) % n]};
			if (prev == curr) {
				c_new[p[i]] = c_new[p[i - 1]];
			} else {
				c_new[p[i]] = c_new[p[i - 1]] + 1;
			}
		}

		c = c_new;
		k++;
	}

	return p;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);



	return 0;
}