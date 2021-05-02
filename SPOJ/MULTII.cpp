/**
 *    author:	vulkan
 *    created:	04.08.2020 10:06:14 AM
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

vector<int> bfs(int n, vector<int> &nums) {
	vector<bool> visited(n);
	vector<pair<int, int>> parent(n, { -1, -1});
	vector<int> first(n);
	queue<int> qu;
	for (int i = 1; i <= 9; ++i) {
		if (find(ALL(nums), i) == nums.end()) {
			int x = i % n;
			if (not visited[x]) {
				qu.push(x);
				visited[x] = true;
				first[x] = i;
			}
		}
	}

	while (not qu.empty()) {
		int x = qu.front();
		if (x == 0) {
			break;
		}

		qu.pop();
		for (int i = 0; i <= 9; ++i) {
			if (find(ALL(nums), i) == nums.end()) {
				int y = (10 * x + i) % n;
				if (not visited[y]) {
					visited[y] = true;
					qu.push(y);
					parent[y] = {x, i};
				}
			}
		}
	}

	vector<int> ans;
	pair<int, int> curr = parent[0];
	if (curr.first == -1) {
		if (first[0]) {
			ans.push_back(first[0]);
		}
	}

	while (curr.first != -1) {
		ans.push_back(curr.second);
		if (parent[curr.first].first == -1) {
			ans.push_back(first[curr.first]);
		}
		curr = parent[curr.first];
	}

	reverse(ALL(ans));

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	int count = 1;
	while (cin >> n and n != 0) {
		int m;
		cin >> m;
		vector<int> nums(m);
		INPUT_ARR(nums, m);

		cout << "Case " << count << ": ";
		vector<int> ans = bfs(n, nums);
		if (not ans.empty()) {
			for (int x : ans) {
				cout << x;
			}
			cout << endl;
		} else {
			cout << -1 << endl;
		}

		count++;
	}

	return 0;
}