/**
 *    author:	vulkan
 *    created:	10.03.2020 06:02:17 PM
**/
#include <bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int> &heights) {
	int n = heights.size();
	if (n == 0) {
		return 0;
	}

	vector<pair<int, int>> small(n);
	stack<int> st;
	for (int i = 0; i < n; ++i) {
		while (not st.empty() and heights[i] < heights[st.top()]) {
			small[st.top()].second = i;
			st.pop();
		}

		if (st.empty()) {
			small[i].first = -1;
		} else {
			small[i].first = st.top();
		}

		st.push(i);
	}

	while (not st.empty()) {
		small[st.top()].second = n;
		st.pop();
	}

	int max_area = INT_MIN;
	for (int i = 0; i < n; ++i) {
		max_area = max({
			max_area,
			(small[i].second - small[i].first - 1) * heights[i]
		});
	}

	return max_area;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> heights(n);
	for (int i = 0; i < n; ++i) {
		cin >> heights[i];
	}

	cout << largestRectangleArea(heights);

	return 0;
}