#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &arr) {
	sort(arr.begin(), arr.end());
	int n = arr.size();
	set<vector<int>> ans;
	for (int i = 0; i < n; ++i) {
		int j = i+1, k = n-1;
		while (j < k) {
			int sum = arr[i] + arr[j] + arr[k];
			if (sum < 0) {
				j++;
			} else if (sum > 0) {
				k--;
			} else {
				ans.insert({arr[i], arr[j], arr[k]});
				j++;
				k--;
			}
		}
	}

	vector<vector<int>> vectorAns;
	for (auto it = ans.begin(); it != ans.end(); ++it) {
		vectorAns.push_back(*it);
	}

	return vectorAns;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	vector<vector<int>> ans = threeSum(arr);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}