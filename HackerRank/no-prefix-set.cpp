/**
 *    author:	vulkan
 *    created:	22.05.2020 11:54:21 PM
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

#define N 6000000
#define CHARSET 'j'-'a'+1

vector<vector<int>> trie(CHARSET, vector<int>(N));
vector<vector<int>> counts(CHARSET, vector<int>(N));
int sz = 0;

void insert(string &s) {
	int v = 0;
	for (char c : s) {
		int x = c - 'a';
		if (::trie[x][v] == 0) {
			::trie[x][v] = ++::sz;
		}

		::counts[x][v]++;
		v = ::trie[x][v];
	}
}

int search(string &s) {
	int v = 0;
	int ans = 0;
	for (char c : s) {
		int x = c - 'a';
		if (::trie[x][v] == 0) {
			return 0;
		}

		ans = ::counts[x][v];
		v = ::trie[x][v];
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> s[i];
		insert(s[i]);
	}

	bool good = true;
	int idx = n;
	for (int i = 0; i <= n - 1; ++i) {
		if (search(s[i]) > 1) {
			for (int j = 0; j <= n - 1; ++j) {
				if (s[i].size() < s[j].size() and s[j].find(s[i]) != s[j].npos) {
					good = false;
					idx = min(idx, j);
					break;
				}
			}
		}
	}

	if (good) {
		cout << "GOOD SET";
	} else {
		cout << "BAD SET\n" << s[idx];
	}

	return 0;
}