/**
 *    author:	vulkan
 *    created:	07.11.2019 11:48:16 AM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define init_arr(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define init_arr2d(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define all(v) v.begin(), v.end()
#define dec_i(a,n) int *a = new int[n]()
#define dec_l(a,n) long *a = new long[n]()
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
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

double find_dist(pii a, pii b) {
	double x1 = a.ff, y1 = a.ss;
	double x2 = b.ff, y2 = b.ss;

	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double phcul(pii start, pii type_1[], pii type_2[], pii type_3[], int n, int m, int k) {
	double start2type_1[n];
	for (int i = 0; i < n; ++i) {
		start2type_1[i] = find_dist(start, type_1[i]);
	}

	double start2type_2[m];
	for (int i = 0; i < m; ++i) {
		start2type_2[i] = find_dist(start, type_2[i]);
	}

	double type_12type_2[n][m];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			type_12type_2[i][j] = find_dist(type_1[i], type_2[j]);
		}
	}

	double second_pts[n + m];
	init_arr(second_pts, n + m, numeric_limits<double>::max());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			second_pts[i] = min(second_pts[i], start2type_2[j] + type_12type_2[i][j]);
		}
	}

	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			second_pts[n + j] = min(second_pts[n + j], start2type_1[i] + type_12type_2[i][j]);
		}
	}

	double second_pts2type_3[n + m][k];
	for (int i = 0; i < n + m; ++i) {
		pii pt_1 = (i < n) ? type_1[i] : type_2[i - n];
		for (int j = 0; j < k; ++j) {
			second_pts2type_3[i][j] = find_dist(pt_1, type_3[j]);
		}
	}

	double ans = numeric_limits<double>::max();
	for (int i = 0; i < n + m; ++i) {
		for (int j = 0; j < k; ++j) {
			ans = min(ans, second_pts[i] + second_pts2type_3[i][j]);
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		pii start;
		cin >> start.ff >> start.ss;
		int n, m, k;
		cin >> n >> m >> k;
		pii type_1[n], type_2[m], type_3[k];
		for (int i = 0; i < n; ++i) {
			cin >> type_1[i].ff >> type_1[i].ss;
		}

		for (int i = 0; i < m; ++i) {
			cin >> type_2[i].ff >> type_2[i].ss;
		}

		for (int i = 0; i < k; ++i) {
			cin >> type_3[i].ff >> type_3[i].ss;
		}

		double ans = phcul(start, type_1, type_2, type_3, n, m, k);
		printf("%.12f\n", ans);
	}

	return 0;
}