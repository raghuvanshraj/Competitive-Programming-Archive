/**
 *    author:	vulkan
 *    created:	21.10.2019 12:26:10 PM
**/
#include <bits/stdc++.h>

using namespace std;

int mural(string walls, int n) {
	int *prefix = new int[n + 1]();
	for (int i = 1; i < n + 1; ++i) {
		prefix[i] = prefix[i - 1] + (walls[i - 1] - '0');
	}

	int w = (n + 1) / 2;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i + w <= n) {
			ans = max(ans, prefix[i + w] - prefix[i]);
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		string walls;
		cin >> walls;

		cout << "Case #" << i + 1 << ": " << mural(walls, n) << endl;
	}

	return 0;
}