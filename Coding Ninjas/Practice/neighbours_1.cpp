#include <bits/stdc++.h>

using namespace std;

vector<int> neighbours(int *arr, int n) {
	
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int *arr = new int[n];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		vector<int> sequence = neighbours(arr, n);
		for (int i = 0; i < sequence.size(); ++i) {
			cout << sequence[i];
		}

		cout << endl;
	}
	return 0;
}