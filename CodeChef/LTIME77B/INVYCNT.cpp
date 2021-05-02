/**
 *    author:	vulkan
 *    created:	26.10.2019 08:27:11 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		long n, k;
		cin >> n >> k;
		long arr[n];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		long f[n], b[n];
		for (int i = 0; i < n; ++i) {
			f[i] = 0;
			b[i] = 0;
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (arr[i] > arr[j]) {
					b[i]++;
				}
			}

			for (int j = i + 1; j < n; ++j) {
				if (arr[i] > arr[j]) {
					f[i]++;
				}
			}
		}

		long f_acc = (long)accumulate(f, f + n, 0);
		long b_acc = (long)accumulate(b, b + n, 0);

		long ans = (f_acc * (k * (k + 1))) + (b_acc * (k * (k - 1)));
		ans /= 2;

		cout << ans << endl;
	}

	return 0;
}