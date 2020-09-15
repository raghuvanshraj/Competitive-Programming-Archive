/**
 *    author:	vulkan
 *    created:	30.08.2019 07:06:05 PM
**/
#include <bits/stdc++.h>
#define MAX_ELT 2001

using namespace std;

pair<int, int> min_max_strength(int counts[], int k, int x) {
	bool convert_current = true;
	while (k--) {
		int *temp = new int[MAX_ELT]();
		for (int i = 0; i < MAX_ELT; ++i) {
			if (counts[i] > 0) {
				if (convert_current) {
					convert_current = false;
					temp[i ^ x] += counts[i];
					temp[i] -= counts[i];
				} else {
					convert_current = true;
				}
			}
		}

		for (int i = 0; i < MAX_ELT; ++i) {
			counts[i] += temp[i];
		}

		delete [] temp;
	}

	pair<int, int> ans;
	for (int i = 0; i < MAX_ELT; ++i) {
		if (counts[i] > 0) {
			ans.second = i;
			break;
		}
	}

	for (int i = MAX_ELT - 1; i >= 0; --i) {
		if (counts[i] > 0) {
			ans.first = i;
			break;
		}
	}
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k, x;
	cin >> n >> k >> x;
	int counts[MAX_ELT];
	for (int i = 0; i < MAX_ELT; ++i) {
		counts[i] = 0;
	}

	for (int i = 0; i < n; ++i) {
		int elt;
		cin >> elt;
		counts[elt]++;
	}

	pair<int, int> ans = min_max_strength(counts, k, x);
	cout << ans.first << ' ' << ans.second;

	return 0;
}