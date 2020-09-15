/**
 *    author:	vulkan
 *    created:	17.03.2020 08:18:31 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define set_arr(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define set_arr2d(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define set_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) arr[i][j][k] = val
#define input_arr(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define input_arr2d(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define input_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) cin >> arr[i][j][k];
#define print_arr(arr,n) for (int i = 0; i < n; ++i) cout << arr[i] << ' '; cout << endl
#define print_arr2d(arr,n,m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << ' '; cout << endl; }

#define all(v) v.begin(), v.end()
#define dec(a,t,n) t *a = new t[n]()
#define dec2d(a,t,n,m) t **a = new t*[n](); for (int i = 0; i < n; ++i) a[i] = new t[m]()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;

typedef priority_queue<int> max_heap;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;

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

void update_intervals(set<pair<int, int>> &intervals, int val) {
	if (intervals.empty()) {
		intervals.insert({val, val});
		return;
	}

	set<pair<int, int>>::iterator it = intervals.lower_bound({val, 0}), prev_it = intervals.end();
	if (it == intervals.end() or it != intervals.begin()) {
		prev_it = prev(it);
	}

	int new_first, new_second;
	if (prev_it != intervals.end() and it != intervals.end()) {
		if (prev_it->second == (it->first) - 2) {
			new_first = prev_it->first;
			new_second = it->second;

			intervals.erase(prev_it);
			intervals.erase(it);
		} else {
			if (prev_it->second == val - 1) {
				new_first = prev_it->first;
				new_second = val;

				intervals.erase(prev_it);
			} else if (it->first == val + 1) {
				new_first = val;
				new_second = it->second;

				intervals.erase(it);
			} else {
				new_first = val;
				new_second = val;
			}
		}
	} else {
		if (it == intervals.end()) {
			if (prev_it->second == val - 1) {
				new_first = prev_it->first;
				new_second = val;

				intervals.erase(prev_it);
			} else {
				new_first = val;
				new_second = val;
			}
		} else if (prev_it == intervals.end()) {
			if (it->first == val + 1) {
				new_first = val;
				new_second = it->second;

				intervals.erase(it);
			} else {
				new_first = val;
				new_second = val;
			}
		}
	}

	intervals.insert({new_first, new_second});
}

pair<int, int> wiggle_walk(int n, int r, int c, int sr, int sc, string ins) {
	sr--;
	sc--;

	vector<set<pair<int, int>>> rows(c), cols(r);
	rows[sc].insert({sr, sr});
	cols[sr].insert({sc, sc});

	pair<int, int> curr_pos = {sr, sc};
	for (int i = 0; i < n; ++i) {
		if (ins[i] == 'N') {
			set<pair<int, int>>::iterator row_it = rows[curr_pos.second].lower_bound({curr_pos.first, 0});
			if (row_it == rows[curr_pos.second].end() or row_it->first > curr_pos.first) {
				row_it = prev(row_it);
			}

			curr_pos.first = (row_it->first) - 1;
		} else if (ins[i] == 'S') {
			set<pair<int, int>>::iterator row_it = rows[curr_pos.second].lower_bound({curr_pos.first, 0});
			if (row_it == rows[curr_pos.second].end() or row_it->first > curr_pos.first) {
				row_it = prev(row_it);
			}

			curr_pos.first = (row_it->second) + 1;
		} else if (ins[i] == 'W') {
			set<pair<int, int>>::iterator col_it = cols[curr_pos.first].lower_bound({curr_pos.second, 0});
			if (col_it == cols[curr_pos.first].end() or col_it->first > curr_pos.second) {
				col_it = prev(col_it);
			}

			curr_pos.second = (col_it->first) - 1;
		} else if (ins[i] == 'E') {
			set<pair<int, int>>::iterator col_it = cols[curr_pos.first].lower_bound({curr_pos.second, 0});
			if (col_it == cols[curr_pos.first].end() or col_it->first > curr_pos.second) {
				col_it = prev(col_it);
			}

			curr_pos.second = (col_it->second) + 1;
		}

		update_intervals(rows[curr_pos.second], curr_pos.first);
		update_intervals(cols[curr_pos.first], curr_pos.second);
	}

	return curr_pos + mp(1, 1);
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int n, r, c, sr, sc;
		cin >> n >> r >> c >> sr >> sc;
		string ins;
		cin >> ins;

		pair<int, int> ans = wiggle_walk(n, r, c, sr, sc, ins);

		cout << "Case #" << t + 1 << ": " << ans.first << ' ' << ans.second << endl;
	}

	return 0;
}