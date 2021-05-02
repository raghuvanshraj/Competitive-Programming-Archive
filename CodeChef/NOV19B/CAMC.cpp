/**
 *    author:	vulkan
 *    created:	07.11.2019 04:12:48 PM
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
typedef priority_queue<int> max_heap;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		min_heap buckets[m];
		for (int i = 0; i < n; ++i) {
			int elt;
			cin >> elt;
			buckets[i % m].push(elt);
		}

		priority_queue<pii, vector<pii>, greater<pii>> min_heap_pairs;
		int max_elt = INT_MIN;
		for (int i = 0; i < m; ++i) {
			int curr_elt = buckets[i].top();
			buckets[i].pop();
			max_elt = max(max_elt, curr_elt);
			min_heap_pairs.push({curr_elt, i});
		}

		int ans = INT_MAX;
		while (min_heap_pairs.size() >= m) {
			pii curr_elt = min_heap_pairs.top();
			min_heap_pairs.pop();
			ans = min(ans, max_elt - curr_elt.ff);
			if (not buckets[curr_elt.ss].empty()) {
				min_heap_pairs.push({buckets[curr_elt.ss].top(), curr_elt.ss});
				max_elt = max(max_elt, buckets[curr_elt.ss].top());
				buckets[curr_elt.ss].pop();
			}
		}

		cout << ans << endl;
	}

	return 0;
}