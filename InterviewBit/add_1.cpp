#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int> &num) {
	int n = num.size();
	vector<int> addedNum;
	int carry = 1;
	for (int i = n-1; i >= 0; --i) {
		int added = num[i] + carry;
		carry = added / 10;
		int add = added % 10;
		addedNum.push_back(add);
	}
	if (carry != 0) {
		addedNum.push_back(carry);
	}

	int m = addedNum.size();
	for (int i = m-1; i >= 0; --i) {
		if (addedNum[i] != 0) {
			break;
		} else {
			addedNum.erase(addedNum.begin() + i);
		}
	}

	reverse(addedNum.begin(), addedNum.end());

	return addedNum;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; ++i) {
		cin >> num[i];
	}

	vector<int> addedNum = plusOne(num);
	for (int i = 0; i < addedNum.size(); ++i) {
		cout << addedNum[i] << ' ';
	}
	return 0;
}