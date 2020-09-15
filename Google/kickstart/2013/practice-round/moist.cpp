/**
 *    author:	vulkan
 *    created:	27.10.2019 03:37:59 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		string name;
		string names[n];
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		for (int i = 0; i < n; ++i) {
			getline(cin, name);
			names[i] = name;
		}

		int ans = 0;
		for (int i = 1; i < n; ++i) {
			if (names[i] < names[i - 1]) {
				ans++;
				swap(names[i], names[i - 1]);
			}
		}

		cout << "Case #" << i + 1 << ": " << ans << endl;
	}

	return 0;
}