/**
 *    author:	vulkan
 *    created:	31.03.2020 07:12:51 PM
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define MOD 1000000007

#define SET_ARR(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define SET_ARR2D(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define INPUT_ARR(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define INPUT_ARR2D(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define PRINT_ARR(arr,n) for (int i = 0; i < n; ++i) cout << arr[i] << ' '; cout << endl
#define PRINT_ARR2D(arr,n,m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << ' '; cout << endl; }

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

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;

		// x2 = min(x+b, x2);
		// x1 = max(x-a, x1);
		// y2 = min(y+d, y2);
		// y1 = max(y-c, y1);

		// int hor_range = abs(x1-x2), vert_range = abs(y1-y2);
		// if (a <= hor_range and b <= hor_range and c <= vert_range and d <= vert_range) {
		// 	cout << "Yes";
		// } else {
		// 	cout << "No";
		// }

		// cout << endl;

		// bool possible = true;

		// long right = min(b, x2-x);
		// b -= right;
		// x += right;

		// long left = min(a, x-x1);
		// a -= left;
		// x -= left;
		// if (a != 0) {
		// 	possible = false;
		// }

		// if (b != 0) {
		// 	right = min(b, x2-x);
		// 	b -= right;
		// 	x += right;
		// 	if (b != 0) {
		// 		possible = false;
		// 	}
		// }

		// long up = min(d, y2-y);
		// d -= up;
		// y += up;

		// long down = min(c, y-y1);
		// c -= down;
		// y -= down;
		// if (c != 0) {
		// 	possible = false;
		// }

		// if (d != 0) {
		// 	up = min(d, y2-y);
		// 	d -= up;
		// 	y += up;
		// 	if (d != 0) {
		// 		possible = false;
		// 	}
		// }

		// string ans = possible ? "Yes" : "No";
		// cout << ans << endl;

		if (x1 == x2 and (a != 0 or b != 0)) {
			cout << "no";
		} else if (y1 == y2 and (c != 0 or d != 0)) {
			cout << "no";
		} else {
			int final_x = x + b - a, final_y = y + d - c;
			if (x1 > final_x or final_x > x2) {
				cout << "no";
			} else if (y1 > final_y or final_y > y2) {
				cout << "no";
			} else {
				cout << "yes";
			}
		}

		cout << endl;
	}

	return 0;
}