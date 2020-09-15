/**
 *    author:	vulkan
 *    created:	26.08.2019 05:41:54 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> searchRange(const vector<int> &arr, int elt) {
	int n = arr.size();
	int first_occurence = -1, last_occurence = -1;

	int i = 0, j = n - 1;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (arr[mid] > elt) {
			j = mid - 1;
		} else if (arr[mid] < elt) {
			i = mid + 1;
		} else {
			first_occurence = mid;
			j = mid - 1;
		}
	}

	i = 0;
	j = n - 1;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (arr[mid] > elt) {
			j = mid - 1;
		} else if (arr[mid] < elt) {
			i = mid + 1;
		} else {
			last_occurence = mid;
			i = mid + 1;
		}
	}

	return {first_occurence, last_occurence};
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int elt;
	cin >> elt;

	vector<int> positions = searchRange(arr, elt);
	for (int i = 0; i < positions.size(); ++i) {
		cout << positions[i] << ' ';
	}

	return 0;
}