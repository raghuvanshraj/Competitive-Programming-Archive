#include <bits/stdc++.h>

using namespace std;

map<char, string> keypad;

void _printKeypad(string input, string output) {

	if (input.empty()) {
		
		cout << output << endl;
		return;
	}

	string curr = keypad[input[0]];
	for (int i = 0; i < curr.size(); ++i) {
		
		_printKeypad(input.substr(1), output + curr[i]);
	}
}

void printKeypad(int num) {

	string input = to_string(num);
  	string alpha[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  	for (int c = '2', i = 0; c <= '9'; ++c, ++i) {
  		
  		keypad[c] = alpha[i];
  	}

	_printKeypad(input, "");
}

int main(int argc, char const *argv[]) {
	
	int num;
	cin >> num;
	printKeypad(num);
	return 0;
}