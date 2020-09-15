#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int n,t;
	cin >> n >> t;
	int *a = new int[n-1];
	for (int i = 0; i < n-1; ++i) {
		cin >> a[i];
	}

	int curr = 0;
	bool reached = false;
	while (curr < n-1) {
		curr += a[curr];
		if (curr == t-1) {
			cout << "YES";
			reached = true;
			break;
		}
	}

	if (not reached) {
		cout << "NO";
	}

	return 0;
}