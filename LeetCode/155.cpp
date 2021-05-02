/**
 *    author:	vulkan
 *    created:	10.04.2020 02:42:33 PM
**/
#include <bits/stdc++.h>

using namespace std;

class MinStack {
	multiset<int> min_elts;
	stack<int> st;
public:
	MinStack() {
	}

	void push(int x) {
		this->st.push(x);
		this->min_elts.insert(x);
	}

	void pop() {
		this->min_elts.erase(this->min_elts.lower_bound(st.top()));
		this->st.pop();
	}

	int top() {
		return this->st.top();
	}

	int getMin() {
		if (not this->min_elts.empty()) {
			return *(this->min_elts.begin());
		}

		return -1;
	}
};

int main(int argc, char const *argv[]) {
	MinStack st;
	int m;
	cin >> m;
	while (m--) {
		string s;
		cin >> s;
		if (s == "push") {
			int elt;
			cin >> elt;
			st.push(elt);
		} else if (s == "pop") {
			st.pop();
		} else if (s == "top") {
			cout << st.top() << endl;
		} else if (s == "getMin") {
			cout << st.getMin() << endl;
		}
	}

	return 0;
}