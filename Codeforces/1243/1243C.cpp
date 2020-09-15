/**
 *    author:	vulkan
 *    created:	06.11.2019 09:36:43 PM
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

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long n;
	cin >> n;
	int prime_count = 0;
	bool is_possible = true;
	long ans = -1;
	long temp = n;
	for (int i = 2; i * i <= temp; ++i) {
		if (temp % i == 0) {
			if (prime_count == 1) {
				is_possible = false;
				break;
			} else {
				prime_count++;
				while (temp % i == 0) {
					temp /= i;
				}

				ans = i;
			}
		}
	}

	if (temp == n) {
		ans = n;
	} else if (temp > 2) {
		is_possible = false;
	}

	if (is_possible) {
		cout << ans;
	} else {
		cout << 1;
	}

	return 0;
}