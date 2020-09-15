#include <bits/stdc++.h>

using namespace std;

int jump(vector<int> &arr) {
	
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << jump(arr);
	
	return 0;
}