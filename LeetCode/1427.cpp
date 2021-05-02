/**
 *    author:	vulkan
 *    created:	14.04.2020 01:00:10 PM
**/
#include <bits/stdc++.h>

using namespace std;

string stringShift(string s, vector<vector<int>> &shifts) {
	int final_shift = 0;
	for (vector<int> x : shifts) {
		if (x[0] == 0) {
			final_shift -= x[1];
		} else {
			final_shift += x[1];
		}
	}

	int n = s.size();
	if (final_shift < 0) {
		final_shift *= -1;
		final_shift %= n;
		final_shift *= -1;
	} else {
		final_shift %= n;
	}

	string ans(n,' ');
	for (int i = 0; i < n; ++i) {
		ans[i] = s[(i - final_shift + n) % n];
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;
	int n;
	cin >> n;
	vector<vector<int>> shifts(n, vector<int>(2));
	for (int i = 0; i < n; ++i) {
		cin >> shifts[i][0] >> shifts[i][1];
	}

	cout << stringShift(s, shifts);

	return 0;
}