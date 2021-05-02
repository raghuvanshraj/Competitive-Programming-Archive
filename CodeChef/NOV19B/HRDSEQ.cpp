/**
 *    author:	vulkan
 *    created:	07.11.2019 11:02:13 AM
**/
#include <bits/stdc++.h>

#define MOD 1000000007
#define MAX_IDX 128

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
typedef vector<int> vi;
typedef vector<string> vs;
typedef queue<int> qi;
typedef pair<int, int> pii;
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
		int n;
		cin >> n;
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}

		int last_idx[MAX_IDX];
		mii idxs;
		mii counts;
		counts[0] = 2;
		init_arr(last_idx, MAX_IDX, -1);
		int last_elt = 0;
		last_idx[0] = 0;
		idxs[0] = 0;
		int curr_available_idx = 1;
		for (int i = 2; i < n; ++i) {
			int idx = idxs[last_elt];
			if (last_idx[idx] != -1) {
				last_elt = i - 1 - last_idx[idx];
				if (idxs.find(last_elt) == idxs.end()) {
					idxs[last_elt] = curr_available_idx;
					last_idx[curr_available_idx++] = i;
				}

				last_idx[idx] = i - 1;
			} else {
				last_elt = 0;
				last_idx[0] = i;
			}

			counts[last_elt]++;
		}

		cout << counts[last_elt] << endl;
	}

	return 0;
}