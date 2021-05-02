#include <bits/stdc++.h>

using namespace std;

long cirMerge(vector<int> arr) {
	
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		cout << cirMerge(arr) << endl;
	}
	return 0;
}