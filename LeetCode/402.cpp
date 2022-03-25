/**
 *    author:	vulkan
 *    created:	07.03.2022 12:10:35 PM
**/
#include <bits/stdc++.h>

using namespace std;

string removeKdigits(string num, int k) {
	stack<int> st;
	st.push(0);
	int n = num.size();
	for (int i = 0; i <= n - 1; ++i) {
		int x = num[i] - '0';
		while (st.top() > x and st.size() - 2 + n - i >= n - k) {
			st.pop();
		}
		if (st.size() - 1 < n - k) {
			st.push(x);
		}
	}

	n = st.size() - 1;
	string ans(n, ' ');
	for (int i = n - 1; i >= 0; --i) {
		ans[i] = '0' + st.top();
		st.pop();
	}

	int i = 0;
	while (i < n and ans[i] == '0') {
		i++;
	}
	if (i == n) {
		return "0";
	}

	return ans.substr(i);
}

int main(int argc, char const *argv[]) {
	string num;
	int k;
	cin >> num >> k;

	cout << removeKdigits(num, k);

	return 0;
}