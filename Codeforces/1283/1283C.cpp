/**
 *    author:	vulkan
 *    created:	29.01.2020 09:47:42 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define init_arr(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define init_arr2d(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define init_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) arr[i][j][k] = val
#define input_arr(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define input_arr2d(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define input_arr3d(arr,n,m,l,val) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) for (int k = 0; k < l; ++k) cin >> arr[i][j][k];
#define all(v) v.begin(), v.end()
#define dec(a,t,n) t *a = new t[n]()
#define dec2d(a,t,n,m) t **a = new t*[n](); for (int i = 0; i < n; ++i) a[i] = new t[m]()
#define pb push_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef queue<int> qi;
typedef priority_queue<int> max_heap;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type
    >
pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {
	return {a.first + b.first, a.second + b.second};
}

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type
    >
pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) {
	return {a.first - b.first, a.second - b.second};
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[n];
	input_arr(arr, n);

	for (int i = 0; i < n; ++i) {
		arr[i]--;
	}

	bool giving[n], recieving[n];
	init_arr(giving, n, false);
	init_arr(recieving, n, false);

	for (int i = 0; i < n; ++i) {
		if (arr[i] != -1) {
			giving[i] = true;
			recieving[arr[i]] = true;
		}
	}

	queue<int> ngnr, ngr, gnr;
	for (int i = 0; i < n; ++i) {
		if (not giving[i] and not recieving[i]) {
			ngnr.push(i);
		} else if (not giving[i] and recieving[i]) {
			ngr.push(i);
		} else if (giving[i] and not recieving[i]) {
			gnr.push(i);
		}
	}

	while (not ngr.empty()) {
		if (ngnr.empty()) {
			arr[ngr.front()] = gnr.front();
			ngr.pop();
			gnr.pop();
		} else {
			int start = ngr.front();

			while (not ngnr.empty()) {
				arr[start] = ngnr.front();
				start = ngnr.front();
				ngnr.pop();
			}

			arr[start] = gnr.front();
			ngr.pop();
			gnr.pop();
		}
	}

	if (not ngnr.empty()) {
		int start = ngnr.front();
		int temp = start;
		ngnr.pop();
		while (not ngnr.empty()) {
			arr[start] = ngnr.front();
			start = ngnr.front();
			ngnr.pop();
		}

		arr[start] = temp;
	}

	for (int i = 0; i < n; ++i) {
		cout << arr[i] + 1 << ' ';
	}

	return 0;
}