/**
 *    author:	vulkan
 *    created:	22.11.2020 02:09:05 PM
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

int ask_xor(int i, int j) {
	cout << "XOR " << i + 1 << ' ' << j + 1 << endl;
	int x;
	cin >> x;
	return x;
}

int ask_and(int i, int j) {
	cout << "AND " << i + 1 << ' ' << j + 1 << endl;
	int x;
	cin >> x;
	return x;
}

tuple<int, int, int> solve(int sij, int sjk, int sik) {
	int dik = sij - sjk;
	int i = (sik + dik) / 2;
	int k = (sik - dik) / 2;
	int j = sij - i;

	return make_tuple(i, j, k);
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> xors(n), arr(n);
	for (int i = 1; i <= n - 1; ++i) {
		xors[i] = ask_xor(0, i);
	}

	int found_idx = -1;
	for (int i = 0; i <= n - 1; ++i) {
		for (int j = i + 1; j <= n - 1; ++j) {
			int curr_xor = xors[i] ^ xors[j];
			if (curr_xor == 0) {
				arr[i] = arr[j] = ask_and(i, j);
				found_idx = i;
				break;
			}
		}
		if (found_idx != -1) {
			break;
		}
	}

	if (found_idx != -1) {
		arr[0] = xors[found_idx] ^ arr[found_idx];
		for (int i = 1; i <= n - 1; ++i) {
			if (i != found_idx) {
				arr[i] = xors[i] ^ arr[0];
			}
		}
	} else {
		int i = 1;
		while (i < n) {
			if (xors[i] == n - 1) {
				break;
			}
			i++;
		}

		int j = 1;
		while (j < n) {
			if (j != i) {
				break;
			}
			j++;
		}

		int x0j = xors[j];
		int xji = xors[j] ^ xors[i];
		int x0i = xors[i];
		int aji = ask_and(j, i);
		int a0j = ask_and(0, j);

		int s0j = x0j + 2 * a0j;
		int sji = xji + 2 * aji;
		int s0i = x0i;

		tie(arr[0], arr[j], arr[i]) = solve(s0j, sji, s0i);
		for (int i = 1; i <= n - 1; ++i) {
			arr[i] = xors[i] ^ arr[0];
		}
	}

	cout << "! ";
	PRINT_ARR(arr);

	return 0;
}