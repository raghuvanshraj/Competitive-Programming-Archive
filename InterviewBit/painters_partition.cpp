/**
 *    author:	vulkan
 *    created:	27.08.2019 09:08:59 AM
**/
#include <bits/stdc++.h>
#define MOD 10000003

using namespace std;

int get_n_painters(vector<int> &boards, int max_len) {
	int total = 0;
	int n = boards.size();
	int count = 1;
	for (int i = 0; i < n; ++i) {
		total += boards[i];
		if (total > max_len) {
			total = boards[i];
			count++;
		}
	}

	return count;
}

int paint(int k, int t, vector<int> &boards) {
	int l = *max_element(boards.begin(), boards.end());
	int r = accumulate(boards.begin(), boards.end(), 0);

	while (l < r) {
		int mid = (l + r) / 2;
		int n_painters = get_n_painters(boards, mid);

		if (n_painters <= k) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	return (l % MOD * t % MOD) % MOD;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> boards(n);
	for (int i = 0; i < n; ++i) {
		cin >> boards[i];
	}

	int k, t;
	cin >> k >> t;

	cout << paint(k, t, boards);

	return 0;
}