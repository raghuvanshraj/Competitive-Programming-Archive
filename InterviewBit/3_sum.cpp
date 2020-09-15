#include <bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int> &arr, int target) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int ans;
    int diff = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int j = i+1, k = n-1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (diff > abs(sum - target)) {
                ans = sum;
                diff = abs(sum - target);
            }
            
            if (sum < target) {
                j++;
            } else {
                k--;
            }
        }
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

	int target;
	cin >> target;

	cout << threeSumClosest(arr, target);
	return 0;
}