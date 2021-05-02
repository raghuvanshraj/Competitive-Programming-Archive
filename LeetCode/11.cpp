/**
 *    author:	raghuvanshraj
 *    created:	17.11.2020 08:55:18 AM
**/
#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int> &heights) {
	int n = heights.size();
	int i = 0, j = n - 1;
	int ans = (n - 1) * min(heights[i], heights[j]);
	while (i < j) {
		if (heights[i] < heights[j]) {
			i++;
		} else {
			j--;
		}

		ans = max({
			ans,
			(j - i) * min(heights[i], heights[j])
		});
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> heights(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> heights[i];
	}

	cout << maxArea(heights);

	return 0;
}