/**
 *    author:	vulkan
 *    created:	02.09.2019 01:37:43 PM
**/
#include <bits/stdc++.h>

using namespace std;

int min_plants(int arr[], int n, int k) {
	int start = 0, end = k;
	vector<int> plant_positions;
	while (start <= end) {
		int curr_plant_position = -1;
		for (int i = start; i < end; ++i) {
			if (arr[i] == 1) {
				curr_plant_position = i;
			}
		}

		if (curr_plant_position == -1) {
			return -1;
		} else {
			plant_positions.push_back(curr_plant_position);
			if (curr_plant_position + k - 1 >= n - 1) {
				break;
			}

			start = curr_plant_position + 1;
			end = min(curr_plant_position + 2 * k - 1, n - 1) + 1;
		}
	}

	return plant_positions.size();
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << min_plants(arr, n, k);

	return 0;
}