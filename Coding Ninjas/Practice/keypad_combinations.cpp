#include <bits/stdc++.h>
#define MAX 100000000

using namespace std;

map<char, string> relate;

int _keypad(string input, string *combinations) {

	if (input.empty()) {
		
		combinations[0] = "";
		return 1;
	}

	int smallOutputSize = _keypad(input.substr(1), combinations);
	string curr = relate[input[0]];
	string *temp = new string[smallOutputSize * curr.size()];

	int k = 0;
	for (int j = 0; j < curr.size(); ++j) {
		
		for (int i = 0; i < smallOutputSize; ++i) {
				
			temp[k++] = curr[j] + combinations[i];
		}
	}

	for (int i = 0; i < smallOutputSize * curr.size(); ++i) {
		
		combinations[i] = temp[i];
	}

	return smallOutputSize * curr.size();
}

int keypad(int num, string *combinations) {

	string input = to_string(num);
	string alpha[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	for (char c = '2', i = 0; c <= '9'; ++c, ++i) {
		
		relate[c] = alpha[i];
	}

	return _keypad(input, combinations);
}

int main(int argc, char const *argv[]) {
	
	int num;
	cin >> num;
	string *combinations = new string[MAX]();
	int size = keypad(num, combinations);
	// cout << size << endl;
	for (int i = 0; i < size; ++i) {
		
		cout << combinations[i] << endl;
	}
	return 0;
}