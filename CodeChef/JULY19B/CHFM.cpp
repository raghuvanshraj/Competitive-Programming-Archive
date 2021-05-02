#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long *arr = new long[n]();
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			sum += arr[i];
		}

		bool flag = false;
		for (int i = 0; i < n; ++i) {
			if (n * arr[i] == sum) {
				cout << i + 1 << endl;
				flag = true;
				break;
			}
		}

		if (!flag) {
			cout << "Impossible\n";
		}
	}
	return 0;
}