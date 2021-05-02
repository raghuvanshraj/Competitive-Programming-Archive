/**
 *    author:	vulkan
 *    created:	01.10.2019 01:05:43 PM
**/
#include <bits/stdc++.h>
#define MAX_DIGS 9

using namespace std;

int get_nos(int len) {
	int all_nos[MAX_DIGS];
	int unique_nos[MAX_DIGS];
	for (int i = 0; i < len; ++i) {
		all_nos[i] = 0;
		unique_nos[i] = 0;
	}

	all_nos[1] = 9;
	all_nos[2] = 90;
	unique_nos[1] = 9;
	unique_nos[2] = 81;
	for (int i = 3; i < len; ++i) {
		all_nos[i] = all_nos[i - 1] * 10;
		unique_nos[i] = (i <= 10) ? unique_nos[i - 1] * (10 - (i - 1)) : 0;
	}

	return accumulate(all_nos, all_nos + len, 0) - accumulate(unique_nos, unique_nos + len, 0);
}

int numDupDigitsAtMostN(int n) {
	vector<int> digits;
	int temp = n;
	while (temp) {
		digits.push_back(temp % 10);
		temp /= 10;
	}

	while (digits[digits.size() - 1] == 0) {
		digits.pop_back();
	}

	reverse(digits.begin(), digits.end());

	int len = digits.size();

	int dp[len + 1];
	for (int i = 0; i < len + 1; ++i) {
		dp[i] = 0;
	}

	bool flag = false;
	bool visited[10];
	for (int i = 0; i < 10; ++i) {
		visited[i] = false;
	}

	for (int i = 1; i < min(10, len) + 1; ++i) {
		if (i == 1)  {
			dp[i] = digits[i - 1];
		} else {
			if (flag) {
				dp[i] = dp[i - 1] * max(10 - (i - 1), 0);
			} else {
				dp[i] = (dp[i - 1] - 1) * max(10 - (i - 1), 0);
				int count = digits[i - 1] + 1;
				for (int j = 0; j < min(10, digits[i - 1] + 1); ++j) {
					if (visited[j]) {
						count--;
					}

					if (count == 0) {
						break;
					}
				}

				dp[i] += count;
			}
		}

		if (visited[digits[i - 1]]) {
			flag = true;
		} else {
			visited[digits[i - 1]] = true;
		}
	}

	int all_len_nos = n - (int)pow(10, len - 1) + 1;
	int n_ans = all_len_nos - dp[len];
	int lesser_nos = get_nos(len);
	int ans = lesser_nos + n_ans;

	return ans;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	cout << numDupDigitsAtMostN(n);

	return 0;
}