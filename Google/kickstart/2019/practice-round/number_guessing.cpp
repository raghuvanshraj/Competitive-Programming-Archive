/**
 *    author:	vulkan
 *    created:	21.10.2019 11:15:12 AM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cout.flush();

		int a, b;
		cin >> a >> b;
		int n;
		cin >> n;
		string is_correct;
		bool solved = false;
		while (n--) {
			int mid = (a + b + 1) / 2;
			cout << mid << endl;
			cin >> is_correct;
			if (is_correct == "CORRECT") {
				solved = true;
				break;
			} else if (is_correct == "TOO_SMALL") {
				a = mid + 1;
			} else if (is_correct == "TOO_BIG") {
				b = mid - 1;
			}
		}

		if (not solved) {
			cin >> is_correct;
		}
	}

	return 0;
}