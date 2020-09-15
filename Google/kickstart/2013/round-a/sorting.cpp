/**
 *    author:	vulkan
 *    created:	28.10.2019 06:18:40 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int n;
		cin >> n;
		vector<int> even_nums;
		vector<int> odd_nums;
		bool *is_odd = new bool[n]();
		for (int i = 0; i < n; ++i) {
			int elt;
			cin >> elt;
			is_odd[i] = elt % 2;
			if (is_odd[i]) {
				odd_nums.push_back(elt);
			} else {
				even_nums.push_back(elt);
			}
		}

		sort(odd_nums.begin(), odd_nums.end());
		sort(even_nums.begin(), even_nums.end(), greater<int>());

		int odd_size = odd_nums.size(), even_size = even_nums.size();
		int final_sequence[n];
		int i = 0, j = 0, k = 0;
		while (i < odd_size and j < even_size) {
			if (is_odd[k]) {
				final_sequence[k++] = odd_nums[i++];
			} else {
				final_sequence[k++] = even_nums[j++];
			}
		}

		while (i < odd_size) {
			final_sequence[k++] = odd_nums[i++];
		}

		while (j < even_size) {
			final_sequence[k++] = even_nums[j++];
		}

		cout << "Case #" << t + 1 << ": ";
		for (int i = 0; i < n; ++i) {
			cout << final_sequence[i] << ' ';
		}

		cout << endl;
	}

	return 0;
}