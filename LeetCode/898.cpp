/**
 *    author:	vulkan
 *    created:	10.06.2020 02:26:32 PM
**/
#include <bits/stdc++.h>

using namespace std;

int subarrayBitwiseORs(vector<int> &arr) {
	set<int> ans, ending_prev, ending_here;
	for (int x : arr) {
		ending_here = {x};
		for (int y : ending_prev) {
			ending_here.insert(x | y);
		}

		ans.insert(ending_here.begin(), ending_here.end());
		ending_prev = ending_here;
	}

	return ans.size();
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}

	cout << subarrayBitwiseORs(arr);

	return 0;
}