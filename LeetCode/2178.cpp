/**
 *    author:	vulkan
 *    created:	27.02.2022 09:22:33 AM
**/
#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

vector<LL> maximumEvenSplit(LL s) {
	if (s & 1) {
		return vector<LL>();
	}

	vector<LL> ans;
	LL i = 2;
	while (s - i >= 0) {
		ans.push_back(i);
		s -= i;
		i += 2;
	}

	int n = ans.size();
	ans[n - 1] += s;

	return ans;
}

int main(int argc, char const *argv[]) {
	LL s;
	cin >> s;

	vector<LL> ans = maximumEvenSplit(s);
	for (LL x : ans) {
		cout << x << endl;
	}

	return 0;
}