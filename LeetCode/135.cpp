/**
 *    author:	vulkan
 *    created:	23.05.2020 11:49:21 PM
**/
#include <bits/stdc++.h>

using namespace std;

int candy(vector<int> &ratings) {
	int n = ratings.size();
	vector<int> ans(n, 1);
	for (int i = 1; i <= n - 1; ++i) {
		if (ratings[i] > ratings[i - 1]) {
			ans[i] = ans[i - 1] + 1;
		}
	}

	for (int i = n - 2; i >= 0; --i) {
		if (ratings[i] > ratings[i + 1] and ans[i] <= ans[i + 1]) {
			ans[i] = ans[i + 1] + 1;
		}
	}

	return accumulate(ans.begin(), ans.end(), 0);
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> ratings(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> ratings[i];
	}

	cout << candy(ratings);

	return 0;
}