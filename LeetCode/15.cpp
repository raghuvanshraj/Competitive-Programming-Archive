/**
 *    author:	vulkan
 *    created:	15.01.2022 11:45:25 AM
**/
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &arr) {
	sort(arr.begin(), arr.end());
	int n = arr.size();
	vector<vector<int>> ans;
	for (int i = 0; i <= n - 1; ++i) {
		int s = i + 1, e = n - 1;
		while (s < e) {
			int x = -(arr[s] + arr[e]);
			if (x < arr[i]) {
				e--;
			} else if (x > arr[i]) {
				s++;
			} else {
				vector<int> curr_ans({arr[i], arr[s], arr[e]});
				ans.push_back(curr_ans);
				while (s < e and arr[s] == curr_ans[1]) {
					s++;
				}
				while (s < e and arr[e] == curr_ans[2]) {
					e--;
				}
			}
		}
		while (i + 1 <= n - 1 and arr[i + 1] == arr[i]) {
			i++;
		}
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

	vector<vector<int>> ans = threeSum(arr);
	for (auto x : ans) {
		for (int y : x) {
			cout << y << ' ';
		}
		cout << endl;
	}

	return 0;
}