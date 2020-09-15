/**
 *    author:	vulkan
 *    created:	13.04.2020 06:45:49 PM
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

bool f(vector<int> &arr1, vector<int> &arr2, int d) {
	int a = 0, b = 0;
	for (int x : arr1) {
		if (x <= d) {
			a += 2;
		} else {
			a += 3;
		}
	}

	for (int x : arr2) {
		if (x <= d) {
			b += 2;
		} else {
			b += 3;
		}
	}

	return a - b;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr1(n);
	INPUT_ARR(arr1, n);
	int m;
	cin >> m;
	vector<int> arr2(m);
	INPUT_ARR(arr2, m);

	sort(ALL(arr1));
	sort(ALL(arr2));

	int i = 0, j = 0;
	int a = 3 * n, b = 3 * m;
	int curr_a = a, curr_b = b;
	int max_diff = a - b;
	int curr_diff = max_diff;
	while (i < n and j < m) {
		if (arr1[i] < arr2[j]) {
			i++;
			curr_diff--;
			curr_a--;
		} else if (arr1[i] > arr2[j]) {
			j++;
			curr_diff++;
			curr_b--;
		} else {
			curr_a--;
			curr_b--;
			i++;
			j++;
		}

		if (curr_diff > max_diff) {
			max_diff = curr_diff;
			a = curr_a;
			b = curr_b;
		}
	}

	if (j < m) {
		if (max_diff < 2 * (n - m)) {
			a = 2 * n;
			b = 2 * m;
		}
	}

	cout << a << ':' << b;

	return 0;
}