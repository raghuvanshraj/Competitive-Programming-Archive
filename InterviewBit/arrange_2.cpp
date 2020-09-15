#include <bits/stdc++.h>

using namespace std;

int arrange(string s, int k) {
	int n = s.size();
	int **prefix = new int*[n+1]();
	for (int i = 0; i < n+1; ++i) {
		prefix[i] = new int[k+1]();
	}

	int **suffix = new int*[n+1]();
	for (int i = 0; i < n+1; ++i) {
		suffix[i] = new int[k+1]();
	}

	int white_count = 0, black_count = 0;
	for (int i = 1; i < n+1; ++i) {
		prefix[i][1] = white_count * black_count;
		if (s[i-1] == 'W') {
			white_count++;
		} else {
			black_count++;
		}
	}

	for (int i = 2; i < n+1; ++i) {
		for (int j = 2; j < k+1; ++j) {
			prefix[i][j] = INT_MAX;
			int white_count = 0, black_count = 0;
			for (int x = 0; x < i+1; ++x) {
				prefix[i][j] = min(prefix[i][j], prefix[i-x][j-1] + (white_count * black_count));
				if (s[i-x-1] == 'W') {
					white_count++;
				} else {
					black_count++;
				}
			}
		}
	}

	// for (int i = 0; i < n+1; ++i) {
	// 	for (int j = 0; j < k+1; ++j) {
	// 		cout << prefix[i][j] << ' ';
	// 	}

	// 	cout << endl;
	// }

	// return prefix[n][k];
}

int main(int argc, char const *argv[]) {
	string s;
	cin >> s;
	int k;
	cin >> k;
	cout << arrange(s,k);
	
	return 0;
}