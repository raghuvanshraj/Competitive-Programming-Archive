#include <bits/stdc++.h>

using namespace std;

bool isPossibleFunc(int *arr, int n) {
	set<int> uniqueElts;
	for (int i = 0; i < n; ++i) {
		uniqueElts.insert(arr[i]);
	}

	int m = uniqueElts.size();
	if (m > 3) {
		return false;
	} else if (m < 3) {
		return true;
	}


	int uniqueEltsArr[3];
	int i = 0;
	for (auto it = uniqueElts.begin(); it != uniqueElts.end(); ++it) {
		uniqueEltsArr[i++] = *it;
	}

	if (uniqueEltsArr[0] + uniqueEltsArr[2] == 2 * uniqueEltsArr[1]) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	int *arr = new int[n]();
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	bool isPossible = isPossibleFunc(arr, n);
	string ans = isPossible ? "YES" : "NO";
	cout << ans;
	return 0;
}