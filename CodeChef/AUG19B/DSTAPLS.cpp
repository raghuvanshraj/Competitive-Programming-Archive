#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

string is_not_equal(lli n, lli k) {
	lli nk = n / k;
	if (nk < k) {
		return "YES";
	} else if (nk == k) {
		return "NO";
	} else {
		if (nk % k == 0) {
			return "NO";
		} else {
			return "YES";
		}
	}
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		lli n,k;
		cin >> n >> k;
		cout << is_not_equal(n,k) << endl;
	}
	return 0;
}