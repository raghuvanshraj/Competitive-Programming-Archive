#include <bits/stdc++.h>

using namespace std;

vector<int> prevSmaller(vector<int> &arr) {
	int n = arr.size();
	vector<int> nearest_smaller(n);
	stack<int> st;
	for (int i = 0; i < n; ++i) {
		if (st.empty() or arr[i] > arr[st.top()]) {
			if (st.empty()) {
				nearest_smaller[i] = -1;
			} else {
				nearest_smaller[i] = arr[st.top()];			
			}
		} else {
			while (not st.empty() and arr[st.top()] >= arr[i]) {
				st.pop();
			}

			if (st.empty()) {
				nearest_smaller[i] = -1;
			} else {
				nearest_smaller[i] = arr[st.top()];
			}
		}

		st.push(i);
	}

	return nearest_smaller;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	vector<int> nearest_smaller = prevSmaller(arr);
	for (int i = 0; i < nearest_smaller.size(); ++i) {
		cout << nearest_smaller[i] << ' ';
	}
	
	return 0;
}