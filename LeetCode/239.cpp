/**
 *    author:	vulkan
 *    created:	20.04.2020 08:55:15 PM
**/
#include <bits/stdc++.h>

using namespace std;

void insert_elt(deque<int> &deq, vector<int> &arr, int i) {
	while (not deq.empty() and arr[deq.back()] <= arr[i]) {
		deq.pop_back();
	}

	deq.push_back(i);
}

void delete_idx(deque<int> &deq, int i) {
	while (not deq.empty() and deq.front() <= i) {
		deq.pop_front();
	}
}

vector<int> maxSlidingWindow(vector<int> &arr, int k) {
	int n = arr.size();
	deque<int> deq;
	for (int i = 0; i <= k - 2; ++i) {
		insert_elt(deq, arr, i);
	}

	vector<int> ans;
	for (int i = k - 1, j = 0; i <= n - 1; ++i, ++j) {
		insert_elt(deq, arr, i);
		ans.push_back(arr[deq.front()]);
		delete_idx(deq, j);
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
	int k;
	cin >> k;

	vector<int> ans = maxSlidingWindow(arr, k);
	for (int x : ans) {
		cout << x << ' ';
	}

	return 0;
}