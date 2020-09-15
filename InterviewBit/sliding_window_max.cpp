#include <bits/stdc++.h>

using namespace std;

vector<int> slidingMaximum(const vector<int> &arr, int b) {
	int n = arr.size();
	vector<int> ans;
	if (n <= b) {
		ans.push_back(*max_element(arr.begin(), arr.end()));
		return ans;
	}

	queue<int> q;
	int max_count = 1;
	int max_elt = INT_MIN;
	for (int i = 0; i < b; ++i) {
		if (max_elt < arr[i]) {
			max_elt = arr[i];
			max_count = 1;
		} else if (max_elt == arr[i]) {
			max_count++;
		}

		q.push(arr[i]);
	}

	ans.push_back(max_elt);

	for (int i = 0; i < n-b; ++i) {
		int curr_elt = q.front();
		q.pop();
		if (arr[i+b] > max_elt) {
			max_elt = arr[i+b];
			max_count = 1;
		} else if (curr_elt == max_elt) {
			max_count--;
			if (max_count == 0) {
				if (arr[i+b] == max_elt) {
					max_count++;
				} else {
					max_elt = INT_MIN;
					for (int j = 1; j < b+1; ++j) {
						if (max_elt < arr[i+j]) {
							max_elt = arr[i+j];
							max_count = 1;
						} else if (max_elt == arr[i+j]) {
							max_count++;
						}
					}
				}
			} else if (arr[i+b] == max_elt) {
				max_count++;
			}
		} else if (arr[i+b] == max_elt) {
			max_count++;
		}

		ans.push_back(max_elt);
		q.push(arr[i+b]);
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int b;
	cin >> b;

	vector<int> ans = slidingMaximum(arr, b);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << ' ';
	}
	
	return 0;
}