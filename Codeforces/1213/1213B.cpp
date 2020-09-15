/**
 *    author:	vulkan
 *    created:	30.08.2019 08:14:30 PM
**/
#include <bits/stdc++.h>

using namespace std;

int n_bad_days(int *arr, int n) {
	stack<int> st;
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (st.empty() or arr[i] >= arr[st.top()]) {
			st.push(i);
		} else {
			while (not st.empty() and arr[st.top()] > arr[i]) {
				count++;
				st.pop();
			}

			st.push(i);
		}
	}

	return count;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int *arr = new int[n]();
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		cout << n_bad_days(arr, n) << endl;
	}

	return 0;
}