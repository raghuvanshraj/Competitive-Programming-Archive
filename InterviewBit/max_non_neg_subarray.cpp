#include <bits/stdc++.h>

using namespace std;

vector<int> maxset(vector<int> &arr) {
	int maxStart = -1, maxEnd = -1, currStart = -1, currEnd = -1;
	long long maxSum = INT_MIN;
	int n = arr.size();
	long long currSum = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] >= 0) {
			currSum += arr[i];
			if (currStart == -1) {
				currStart = i;
				currEnd = i;
			} else {
				currEnd++;
			}

			if (currSum > maxSum) {
				maxSum = currSum;
				maxStart = currStart;
				maxEnd = currEnd;
			} else if (currSum == maxSum) {
				if (currEnd - currStart > maxEnd - maxStart) {
					maxSum = currSum;
					maxStart = currStart;
					maxEnd = currEnd;
				}
			}
		} else {
			currStart = -1;
			currEnd = -1;
			currSum = 0;
		}
	}

	if (maxStart == -1) {
		return vector<int>();
	}

	return vector<int>(arr.begin() + maxStart, arr.begin() + maxEnd + 1);
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	vector<int> subArr = maxset(arr);
	for (int i = 0; i < subArr.size(); ++i) {
		cout << subArr[i] << ' ';
	}
	return 0;
}