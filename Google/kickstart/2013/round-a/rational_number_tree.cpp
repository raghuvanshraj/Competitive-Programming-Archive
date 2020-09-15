/**
 *    author:	vulkan
 *    created:	28.10.2019 04:28:49 PM
**/
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << i + 1 << ": ";
		int type;
		cin >> type;
		if (type == 1) {
			ull n;
			cin >> n;
			string operations = "";
			while (n > 1) {
				if (n % 2) {
					operations = "r" + operations;
				} else {
					operations = "l" + operations;
				}

				n /= 2;
			}

			ull p = 1, q = 1;
			int op_size = operations.size();
			for (int i = 0; i < op_size; ++i) {
				if (operations[i] == 'l') {
					q = p + q;
				} else if (operations[i] == 'r') {
					p = p + q;
				}
			}

			cout << p << " " << q;
		} else if (type == 2) {
			ull p, q;
			cin >> p >> q;
			string operations = "";
			while (p != q) {
				if (p > q) {
					p -= q;
					operations = "r" + operations;
				} else {
					q -= p;
					operations = "l" + operations;
				}
			}

			ull idx = 1;
			int op_size = operations.size();
			for (int i = 0; i < op_size; ++i) {
				if (operations[i] == 'l') {
					idx *= 2;
				} else if (operations[i] == 'r') {
					idx = 2 * idx + 1;
				}
			}

			cout << idx;
		}

		cout << endl;
	}

	return 0;
}