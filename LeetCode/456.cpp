/**
 *    author:	vulkan
 *    created:	02.06.2020 05:14:10 PM
**/
#include <bits/stdc++.h>

using namespace std;

bool find132pattern(vector<int> &arr) {
	int n = arr.size();
	int ak = INT_MIN;
	stack<int> st;
	for (int j = n - 1; j >= 0; --j) {
		if (arr[j] < ak) {
			return true;
		}

		while (not st.empty() and arr[j] > arr[st.top()]) {
			ak = max(ak, arr[st.top()]);
			st.pop();
		}

		st.push(j);
	}

	return false;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << find132pattern(arr);

	return 0;
}