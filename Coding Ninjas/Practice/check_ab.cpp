#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

bool checkAB(char s[]) {

	if (s[0] == 'a') {
		
		if (s[1] != 'a' or (s[1] != 'b' and s[2] != 'b')) {
			/* code */
		}
	}
}

int main(int argc, char const *argv[]) {
	
	char s[MAX];
	cin >> s;
	if (s[0] != 'a') {
		
		cout << 'false';
	} else {
		if (checkAB(s)) {
			
			cout << 'true';
		} else {

			cout << 'false';
		}
	}
	return 0;
}