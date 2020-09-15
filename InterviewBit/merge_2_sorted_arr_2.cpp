#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr1, vector<int> &arr2) {
	int n = arr1.size();
	int m = arr2.size();
	vector<int> combined(m+n);

	int i = 0, j = 0, k = 0;
	while (i < n and j < m) {
		if (arr1[i] < arr2[j]) {
			combined[k++] = arr1[i++];
		} else {
			combined[k++] = arr2[j++];
		}
	}

	if (i == n) {
		while (j < m) {
			combined[k++] = arr2[j++];
		}
	} else if (j == m) {
		while (i < n) {
			combined[k++] = arr1[i++];
		}
	}

	arr1 = combined;
}

int main(int argc, char const *argv[]) {
	int n,m;
	cin >> n >> m;
	vector<int> arr1(n), arr2(m);
	for (int i = 0; i < n; ++i) {
		cin >> arr1[i];
	}

	for (int i = 0; i < m; ++i) {
		cin >> arr2[i];
	}

	merge(arr1, arr2);
	for (int i = 0; i < arr1.size(); ++i) {
		cout << arr1[i] << ' ';
	}

	return 0;
}