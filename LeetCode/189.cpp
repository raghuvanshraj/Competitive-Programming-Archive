/**
 *    author:	vulkan
 *    created:	14.01.2022 12:46:40 PM
**/
#include <bits/stdc++.h>

using namespace std;

void rotate(vector<int> &arr, int k) {
	int n = arr.size();
	k %= n;
	int g = __gcd(n, k);
	for (int i = 0; i <= g - 1; ++i) {
		int j = i;
		int x = arr[i];
		while (true) {
			swap(arr[j], x);
			j = (j + k) % n;
			if (j == i) {
				break;
			}
		}
		swap(arr[i], x);
	}
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> arr[i];
	}
	int k;
	cin >> k;

	rotate(arr, k);

	for (int x : arr) {
		cout << x << ' ';
	}

	return 0;
}