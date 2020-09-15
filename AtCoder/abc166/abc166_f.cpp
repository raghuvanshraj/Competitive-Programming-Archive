/**
 *    author:	vulkan
 *    created:	03.05.2020 10:07:24 PM
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

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	vector<string> s(n);
	INPUT_ARR(s, n);

	map<char, int> mp;
	mp['A'] = a;
	mp['B'] = b;
	mp['C'] = c;

	bool possible = true;
	string ans(n, ' ');
	for (int i = 0; i <= n - 1; ++i) {
		int x = mp[s[i][0]], y = mp[s[i][1]];
		if (x == 0 and y == 0) {
			possible = false;
			break;
		} else if (x == 1 and y == 0) {
			ans[i] = s[i][1];
			mp[s[i][1]]++;
			mp[s[i][0]]--;
		} else if (y == 1 and x == 0) {
			ans[i] = s[i][0];
			mp[s[i][0]]++;
			mp[s[i][1]]--;
		} else {
			if (x == y and x == 1) {
				if (i < n - 1) {
					if (s[i + 1] == s[i]) {
						ans[i] = s[i][0];
						ans[i + 1] = s[i][1];
					} else {
						char c;
						if (s[i] == "AB") {
							c = 'C';
						} else if (s[i] == "BC") {
							c = 'A';
						} else if (s[i] == "AC") {
							c = 'B';
						}

						int z = mp[c];
						char a, b;
						for (char c : "ABC") {
							if (count(ALL(s[i]), c) and count(ALL(s[i + 1]), c)) {
								b = c;
							} else if (count(ALL(s[i]), c)) {
								a = c;
							}
						}

						if (z == 0) {
							ans[i] = b;
							ans[i + 1] = c;
							mp[c]++;
							mp[a]--;
						} else {
							ans[i] = a;
							ans[i + 1] = b;
							mp[a]++;
							mp[c]--;
						}
					}

					++i;
				} else {
					ans[i] = s[i][0];
				}
			} else {
				if (x < y) {
					ans[i] = s[i][0];
					mp[s[i][0]]++;
					mp[s[i][1]]--;
				} else {
					ans[i] = s[i][1];
					mp[s[i][1]]++;
					mp[s[i][0]]--;
				}
			}
		}
	}

	if (possible) {
		cout << "Yes\n";
		for (char c : ans) {
			cout << c << "\n";
		}
	} else {
		cout << "No";
	}

	return 0;
}