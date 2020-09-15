#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>

using namespace std;

vector<string> split(string path) {
	vector<string> elts;
	int n = path.size();

	int start = 0, i = 0;
	while (i < n) {
		if (path[i] == '/') {
			elts.push_back(path.substr(start, i-start));
			start = i+1;
		}

		i++;
	}

	if (start < n) {
		elts.push_back(path.substr(start, i-start));
	}

	return elts;
}

string simplifyPath(string abs_path) {
	vector<string> elts = split(abs_path);

	int n = elts.size();
	stack<string> st;
	for (int i = 0; i < n; ++i) {
		if (elts[i] == "") {
			continue;
		}
		
		if (elts[i][0] == '.') {
			int len = elts[i].substr(1).size();
			while (len-- and not st.empty()) {
				st.pop();
			}
		} else {
			st.push(elts[i]);
		}
	}

	if (st.empty()) {
		return "/";
	}

	string result = "";
	while (not st.empty()) {
		string curr = st.top();
		st.pop();
		result = "/" + curr + result;
	}

	return result;
}

int main(int argc, char const *argv[]) {
	string abs_path;
	cin >> abs_path;

	cout << simplifyPath(abs_path);
	
	return 0;
}