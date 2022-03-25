/**
 *    author:	vulkan
 *    created:	07.03.2022 12:31:14 PM
**/
#include <bits/stdc++.h>

using namespace std;

int monotoneIncreasingDigits(int num) {
	int x = num;
	vector<int> dig;
	vector<int> ans;
	int sl = x % 10;
	while (x) {
		int l = sl;
		dig.push_back(x % 10);
		ans.push_back(l);
		x /= 10;
		sl = x % 10;
		if (sl > l) {
			sl--;
		}
	}

	reverse(dig.begin(), dig.end());
	reverse(ans.begin(), ans.end());
	int n = dig.size();
	int i = 0;
	while (i < n) {
		if (dig[i] > ans[i]) {
			break;
		}
		i++;
	}

	int ans_num = 0;
	for (int j = 0; j <= n - 1; ++j) {
		int x = (j <= i) ? ans[j] : 9;
		ans_num *= 10;
		ans_num += x;
	}

	return ans_num;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	cout << monotoneIncreasingDigits(n);

	return 0;
}