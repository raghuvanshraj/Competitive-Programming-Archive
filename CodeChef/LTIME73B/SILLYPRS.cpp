#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		long n;
		cin >> n;

		long ev1 = 0;
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			int elt;
			cin >> elt;
			if (elt % 2 == 0) {
				ev1++;
			}

			sum += elt;
		}

		long ev2 = 0;
		for (int i = 0; i < n; ++i) {
			int elt;
			cin >> elt;
			if (elt % 2 == 0) {
				ev2++;
			}

			sum += elt;
		}

		long diff = abs(ev1 - ev2);
		long long ans = (sum - diff) / 2;

		cout << ans << endl;
	}
	return 0;
}