/**
 *    author:	vulkan
 *    created:	14.04.2020 10:21:03 AM
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

bool comp(pair<int, int> &a, pair<int, int> &b) {
	return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
}

struct move_t {
	int type;
	int k;
	char dir;
};

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> bombs(n);
	INPUT_ARR(bombs, n);

	sort(ALL(bombs), comp);

	vector<move_t> ins;
	for (int i = 0; i < n; ++i) {
		pair<int, int> diff = bombs[i] - make_pair(0, 0);
		if (diff.first > 0) {
			ins.push_back({
				1,
				diff.first,
				'R'
			});
		} else if (diff.first < 0) {
			ins.push_back({
				1,
				-diff.first,
				'L'
			});
		}

		if (diff.second > 0) {
			ins.push_back({
				1,
				diff.second,
				'U'
			});
		} else if (diff.second < 0) {
			ins.push_back({
				1,
				-diff.second,
				'D'
			});
		}

		ins.push_back({
			2,
			-1,
			' '
		});

		if (diff.first > 0) {
			ins.push_back({
				1,
				diff.first,
				'L'
			});
		} else if (diff.first < 0) {
			ins.push_back({
				1,
				-diff.first,
				'R'
			});
		}

		if (diff.second > 0) {
			ins.push_back({
				1,
				diff.second,
				'D'
			});
		} else if (diff.second < 0) {
			ins.push_back({
				1,
				-diff.second,
				'U'
			});
		}

		ins.push_back({
			3,
			-1,
			' '
		});
	}

	cout << ins.size() << endl;
	for (move_t x : ins) {
		cout << x.type << ' ';
		if (x.type == 1) {
			cout << x.k << ' ' << x.dir;
		}

		cout << '\n';
	}

	return 0;
}