/**
 *    author:	vulkan
 *    created:	27.08.2019 09:26:58 AM
**/
#include <bits/stdc++.h>

using namespace std;

int get_n_students(vector<int> &books_arr, int max_len) {
	int total = 0;
	int n = books_arr.size();
	int count = 1;
	for (int i = 0; i < n; ++i) {
		total += books_arr[i];
		if (total > max_len) {
			total = books_arr[i];
			count++;
		}
	}

	return count;
}

int books(vector<int> &books_arr, int m) {
	int n = books_arr.size();
	if (m > n) {
		return -1;
	}

	int l = *max_element(books_arr.begin(), books_arr.end());
	int r = accumulate(books_arr.begin(), books_arr.end(), 0);

	while (l < r) {
		int mid = (l + r) / 2;
		int n_students = get_n_students(books_arr, mid);

		if (n_students <= m) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	return l;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> books_arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> books_arr[i];
	}

	int m;
	cin >> m;

	cout << books(books_arr, m);

	return 0;
}