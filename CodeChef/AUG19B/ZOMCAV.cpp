#include <bits/stdc++.h>

using namespace std;

bool zombie_cave(long *rad_power, long *zombies, int n) {
	long prefix_sum[n];
	for (int i = 0; i < n; ++i) {
		prefix_sum[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		int start = (i - rad_power[i] >= 0) ? i - rad_power[i] : 0;
		int end = (i + rad_power[i] < n) ? i + rad_power[i] : n-1;
		prefix_sum[start]++;
		prefix_sum[end+1]--;
	}

	for (int i = 1; i < n; ++i) {
		prefix_sum[i] += prefix_sum[i-1];
	}

	sort(prefix_sum, prefix_sum+n);
	sort(zombies, zombies+n);

	for (int i = 0; i < n; ++i) {
		if (prefix_sum[i] != zombies[i]) {
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long rad_power[n];
		long zombies[n];
		for (int i = 0; i < n; ++i) {
			cin >> rad_power[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> zombies[i];
		}

		bool is_possible = zombie_cave(rad_power, zombies, n);
		string ans = (is_possible) ? "YES" : "NO";
		cout << ans << endl;
	}

	return 0;
}