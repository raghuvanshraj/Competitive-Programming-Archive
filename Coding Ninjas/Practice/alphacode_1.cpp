#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef unsigned long long ull;

ull alphaCode(int *input, int n) {
	int *output = new int[n+1]();
	output[0] = output[1] = 1;

	for (int i = 2; i < n+1; ++i) {
		if (input[i-1] != 0) {
			output[i] = output[i-1];
		}

		int num = input[i-2] * 10 + input[i-1];
		if (num >= 10 and num <= 26) {
			output[i] = (output[i] + output[i-2]) % MOD;
		}
	}

	return output[n];
}

int main(int argc, char const *argv[]) {
	while (true) {
		string s;
		cin >> s;
		if (s == "0") {
			break;
		}

		int *input = new int[s.size()]();
		for (int i = 0; i < s.size(); ++i) {
			input[i] = s[i] - '0';
		}

		cout << alphaCode(input, s.size()) << endl;
	}
	return 0;
}