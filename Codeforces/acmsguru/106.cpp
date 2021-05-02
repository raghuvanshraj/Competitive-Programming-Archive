/**
 *    author:	vulkan
 *    created:	14.09.2020 08:00:53 PM
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

struct euclid_t {
	LL x;
	LL y;
	LL g;
};

euclid_t extended_euclid(LL a, LL b) {
	euclid_t ans({
		1, 0, a
	});

	LL x1 = 0, y1 = 1, b1 = b;
	while (b1) {
		LL q = ans.g / b1;
		tie(ans.x, x1) = make_tuple(x1, ans.x - q * x1);
		tie(ans.y, y1) = make_tuple(y1, ans.y - q * y1);
		tie(ans.g, b1) = make_tuple(b1, ans.g - q * b1);
	}

	return ans;
}

void shift(LL &x, LL &y, LL a, LL b, LL k) {
	x += k * b;
	y -= k * a;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	LL a, b, c, x1, x2, y1, y2;
	cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
	if (a == 0 and b == 0) {
		cout << (x2 - x1 + 1) * (y2 - y1 + 1);
		return 0;
	}

	c *= -1LL;
	LL g = (LL)__gcd(abs(a), abs(b));
	if (abs(c) % g == 0) {
		a /= g, b /= g, c /= g;
		if (a == 0) {
			if (y1 <= c and c <= y2) {
				cout << (x2 - x1 + 1);
			} else {
				cout << 0;
			}

			return 0;
		} else if (b == 0) {
			if (x1 <= c and c <= x2) {
				cout << (y2 - y1 + 1);
			} else {
				cout << 0;
			}

			return 0;
		}

		euclid_t ans = extended_euclid(abs(a), abs(b));
		LL x = ans.x * c, y = ans.y * c;
		LL sign_a = 1, sign_b = 1;
		if (a < 0) {
			x *= -1LL;
			sign_a = -1;
		}
		if (b < 0) {
			y *= -1LL;
			sign_b = -1;
		}

		shift(x, y, a, b, (x1 - x) / b);
		if (x < x1) {
			shift(x, y, a, b, sign_b);
		}
		if (x > x2) {
			cout << 0;
			return 0;
		}
		LL lx1 = x;

		shift(x, y, a, b, (x2 - x) / b);
		if (x > x2) {
			shift(x, y, a, b, -sign_b);
		}
		LL rx1 = x;

		shift(x, y, a, b, (y - y1) / a);
		if (y < y1) {
			shift(x, y, a, b, -sign_a);
		}
		if (y > y2) {
			cout << 0;
			return 0;
		}
		LL lx2 = x;

		shift(x, y, a, b, (y - y2) / a);
		if (y > y2) {
			shift(x, y, a, b, sign_a);
		}
		LL rx2 = x;

		if (lx2 > rx2) {
			swap(lx2, rx2);
		}
		LL lx = max(lx1, lx2);
		LL rx = min(rx1, rx2);
		if (lx > rx) {
			cout << 0;
			return 0;
		}
		cout << (rx - lx) / abs(b) + 1;
	} else {
		cout << 0;
	}

	return 0;
}