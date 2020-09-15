#include <bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int> &arr) {
	int m = arr.size();
	stack<int> st;
	int max_area = 0, area = 0;
	int i = 0;
	while (i < m) {
		if (st.empty() or arr[i] >= arr[st.top()]) {
			st.push(i++);
		} else {
			int t = st.top();
			st.pop();
			area = arr[t] * i;

			if (not st.empty()) {
				area = arr[t] * (i - st.top() - 1);
			}

			max_area = max(max_area, area);
		}
	}

	while (not st.empty()) {
		int t = st.top();
		st.pop();
		area = arr[t] * i;

		if (not st.empty()) {
			area = arr[t] * (i - st.top() - 1);
		}

		max_area = max(max_area, area);
	}

	return max_area;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << largestRectangleArea(arr);
	
	return 0;
}