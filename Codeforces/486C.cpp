/**
 *    author:	vulkan
 *    created:	30.03.2020 04:20:37 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define SET_ARR(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define SET_ARR2D(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define SET_ARR3D(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) arr[i][j][k] = val
#define INPUT_ARR(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define INPUT_ARR2D(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define INPUT_ARR3D(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) cin >> arr[i][j][k];
#define PRINT_ARR(arr,n) for (int i = 0; i < n; ++i) cout << arr[i] << ' '; cout << endl
#define PRINT_ARR2D(arr,n,m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << ' '; cout << endl; }

#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

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

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, p;
	cin >> n >> p;
	string s;
	cin >> s;

	int i = 0, j = n - 1;
	set<int> pos;
	int cost = 0;
	while (i < j) {
		if (s[i] != s[j]) {
			pos.insert(i);

			cost += min(abs(s[i] - s[j]), 26 - abs(s[i] - s[j]));
		}

		i++;
		j--;
	}

	p--;
	if (p >= n / 2) {
		p = n - 1 - p;
	}

	set<int>::iterator start = pos.begin(), end = pos.end();
	if (pos.size() > 0) {
		end = prev(end);
	}

	int dist1 = (start != pos.end()) ? abs(p - *start) : 0;
	int dist2 = (end != pos.end()) ? abs(p - *end) : 0;
	int dist3 = (start != pos.end()) ? abs(*start - *end) : 0;

	cost += min(dist1, dist2) + dist3;
	cout << cost;

	return 0;
}