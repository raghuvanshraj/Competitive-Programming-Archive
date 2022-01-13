/**
 *    author:	vulkan
 *    created:	13.01.2022 07:15:10 PM
**/
#include <bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int> &arr) {
	stack<int> st;
	int n = arr.size();
	vector<int> ans(n);
	for (int i = 0; i <= n - 1; ++i) {
		while (not st.empty() and arr[i] > arr[st.top()]) {
			ans[st.top()] = i - st.top();
			st.pop();
		}

		st.push(i);
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	vector<int> ans = dailyTemperatures(arr);
	for (int x : ans) {
		cout << x << ' ';
	}

	return 0;
}