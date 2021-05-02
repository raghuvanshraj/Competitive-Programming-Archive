/**
 *    author:	vulkan
 *    created:	12.04.2020 11:12:48 PM
**/
#include <bits/stdc++.h>

using namespace std;

int lastStoneWeight(vector<int> &arr) {
	priority_queue<int> max_heap;
	for (int x : arr) {
		max_heap.push(x);
	}

	while (max_heap.size() > 1) {
		int a = max_heap.top();
		max_heap.pop();
		int b = max_heap.top();
		max_heap.pop();
		if (a != b) {
			max_heap.push(abs(a - b));
		}
	}

	if (max_heap.empty()) {
		return 0;
	} else {
		return max_heap.top();
	}
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << lastStoneWeight(arr);

	return 0;
}