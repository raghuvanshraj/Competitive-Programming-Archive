/**
 *    author:	vulkan
 *    created:	19.10.2019 10:50:58 AM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long n, a, b;
	cin >> n >> a >> b;

	if (a == b) {
		if (n % a == 0) {
			cout << "YES" << endl;
			for (int i = 0; i < n / a; ++i) {
				cout << a << ' ';
			}
		} else {
			cout << "NO";
		}
	} else if (n < a) {
		cout << "NO";
	} else if (n >= a and n <= b) {
		cout << "YES" << endl;
		cout << n;
	} else {
		long x = n % b;
		if (x >= a or x == 0) {
			cout << "YES" << endl;
			if (x != 0) {
				cout << x << ' ';
			}

			for (int i = 0; i < n / b; ++i) {
				cout << b << ' ';
			}
		} else {
			long diff = a - x;
			if (a - x <= b - a) {
				cout << "YES" << endl;
				cout << a << ' ';
				cout << b - a + x << ' ';
				for (int i = 0; i < n / b - 1; ++i) {
					cout << b << ' ';
				}
			} else {
				if ((a - x) % (b - a) == 0) {
					int n_prime = (a - x) / (b - a);
					if (n_prime > n / b) {
						cout << "NO";
					} else {
						cout << "YES" << endl;
						cout << a << ' ';
						for (int i = 0; i < n_prime; ++i) {
							cout << a << ' ';
						}
						for (int i = n_prime; i < n / b; ++i) {
							cout << b << ' ';
						}
					}
				} else {
					int n_prime = (a - x) / (b - a);
					if (n_prime + 1 > n / b) {
						cout << "NO";
					} else {
						cout << "YES" << endl;
						cout << a << ' ';
						for (int i = 0; i < n_prime; ++i) {
							cout << a << ' ';
						}

						cout << b - ((a - x) % (b - a)) << ' ';

						for (int i = n_prime + 1; i < n / b; ++i) {
							cout << b << ' ';
						}
					}
				}
			}
		}
	}

	return 0;
}