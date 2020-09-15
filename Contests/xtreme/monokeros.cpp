/**
 *    author:	vulkan
 *    created:	19.10.2019 07:16:32 PM
**/
#include <bits/stdc++.h>

using namespace std;

struct node_t {
	int ht = 0;
	int right_idx = -1;
	int left_idx = -1;
};

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	node_t nodes[n];
	nodes[0].ht = 1;
	for (int i = 1; i < n; ++i) {
		int j = 0;
		while (j < i) {
			if (arr[i] > arr[j]) {
				if (nodes[j].right_idx == -1) {
					nodes[j].right_idx = i;
					nodes[i].ht = nodes[j].ht + 1;

					break;
				} else {
					j = nodes[j].right_idx;
				}
			} else {
				if (nodes[j].left_idx == -1) {
					nodes[j].left_idx = i;
					nodes[i].ht = nodes[j].ht + 1;

					break;
				} else {
					j = nodes[j].left_idx;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << nodes[i].ht << ' ';
	}

	return 0;
}