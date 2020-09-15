/**
 *    author:	vulkan
 *    created:	04.11.2019 07:39:40 PM
**/
#include <bits/stdc++.h>

#define MOD 1000000007

#define pb push_back
#define all(v) v.begin(), v.end()
#define deci(a,n) int *a = new int[n]()
#define decl(a,n) long *a = new long[n]()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef map<string, int> msi;
typedef map<int, int> mii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, int> umii;
typedef set<int> si;
typedef unordered_set<int> usi;

void swap_bubble(int arr[], int curr_idx, int swap_idx) {
	while (swap_idx > curr_idx) {
		swap(arr[swap_idx], arr[swap_idx - 1]);
		swap_idx--;
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		int op = n - 1;
		int curr_idx = 0;
		while (op > 0) {
			int end_idx = (curr_idx + op < n) ? curr_idx + op : n - 1;
			int swap_idx = min_element(arr + curr_idx, arr + end_idx + 1) - arr;
			swap_bubble(arr, curr_idx, swap_idx);
			op -= (swap_idx - curr_idx);
			curr_idx = (curr_idx != swap_idx) ? swap_idx : curr_idx + 1;
			if (curr_idx == n - 1) {
				break;
			}
		}

		for (int i = 0; i < n; ++i) {
			cout << arr[i] << ' ';
		}

		cout << endl;
	}

	return 0;
}