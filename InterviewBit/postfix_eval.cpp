#include <bits/stdc++.h>

using namespace std;

int convert_to_num(string str_num) {
	int n = str_num.size();
	int num = 0;
	for (int i = 0; i < n; ++i) {
		num = (num * 10) + (str_num[i] - '0');
	}

	return num;
}

int evalRPN(vector<string> &symbols) {
	stack<int> st;
	int n = symbols.size();
	for (int i = 0; i < n; ++i) {
		if (symbols[i] == "+" or
			symbols[i] == "-" or
			symbols[i] == "/" or
			symbols[i] == "*") {

			int b = st.top();
			st.pop();
			int a = st.top();
			st.pop();

			switch (symbols[i][0]) {
				case '+': {
					st.push(a+b);
				}
				break;

				case '-': {
					st.push(a-b);
				}
				break;

				case '*': {
					st.push(a*b);
				}
				break;

				case '/': {
					st.push(a/b);
				}
				break;
			}
		} else {
			if (symbols[i][0] == '-') {
				st.push(convert_to_num(symbols[i].substr(1)) * -1);
			} else {
				st.push(convert_to_num(symbols[i]));
			}
		}
	}

	return st.top();
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<string> symbols(n);
	for (int i = 0; i < n; ++i) {
		cin >> symbols[i];
	}

	cout << evalRPN(symbols);
	
	return 0;
}