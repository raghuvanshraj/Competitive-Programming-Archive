#include <bits/stdc++.h>

using namespace std;

int min_price(pair<int,int> cans[], int n, int m, int k, int l, int r) {
	int final_price = -1;
	for (int i = 0; i < n; ++i) {
		int curr_temp = cans[i].first;
		int curr_price = cans[i].second;

		int final_temp;
		if (curr_temp < k) {
			final_temp = min(k, curr_temp + m);
		} else if (curr_temp > k) {
			final_temp = max(k, curr_temp - m);
		} else {
			final_temp = k;
		}

		if (final_temp >= l and final_temp <= r) {
			if (final_price == -1) {
				final_price = curr_price;
			} else {
				final_price = min(final_price, curr_price);
			}
		}
	}

	return final_price;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n,m,k,l,r;
		cin >> n >> m >> k >> l >> r;
		pair<int,int> cans[n] = {{0,0}};
		for (int i = 0; i < n; ++i) {
			cin >> cans[i].first >> cans[i].second;
		}

		cout << min_price(cans, n, m, k, l, r) << endl;
	}
	
	return 0;
}