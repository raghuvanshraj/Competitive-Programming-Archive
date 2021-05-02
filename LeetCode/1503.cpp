/**
 *    author:	vulkan
 *    created:	16.08.2020 11:50:10 PM
**/
#include <bits/stdc++.h>

using namespace std;

int getLastMoment(int n, vector<int> &left, vector<int> &right) {
	sort(left.begin(), left.end(), greater<int>());
	sort(right.begin(), right.end());

	if (left.empty() and right.empty()) {
		return 0;
	} else if (left.empty()) {
		return n - right[0];
	} else if (right.empty()) {
		return left[0];
	} else {
		return max(left[0], n - right[0]);
	}
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	int left_sz, right_sz;
	cin >> left_sz >> right_sz;
	vector<int> left(left_sz), right(right_sz);
	for (int i = 0; i <= left_sz - 1; ++i) {
		cin >> left[i];
	}
	for (int i = 0; i <= right_sz; ++i) {
		cin >> right[i];
	}

	cout << getLastMoment(n, left, right);

	return 0;
}