/**
 *    author:	vulkan
 *    created:	24.05.2020 12:16:40 AM
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

bool isPossible(vector<int> &target) {
	int n = target.size();
	priority_queue<int> max_heap(target.begin(), target.end());
	LL s = accumulate(target.begin(), target.end(), 0LL);
	while (s > 1 and max_heap.top() > s / 2) {
		int curr = max_heap.top();
		max_heap.pop();
		s -= curr;
		if (s <= 1) {
			return s;
		}

		max_heap.push(curr % s);
		s += curr % s;
	}

	return s == n;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> target(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> target[i];
	}

	cout << isPossible(target);

	return 0;
}