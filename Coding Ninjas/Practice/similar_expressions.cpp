#include <bits/stdc++.h>
#define MAX 100
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

using namespace std;

string convert(string s) {
	char temp[MAX];
	int j = 0;
	stack<char> currSign;
	currSign.push('+');
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'a' and s[i] <= 'z') {
			char letterSign;
			if (i == 0 or s[i-1] == '(') {
				letterSign = '+';
			} else {
				letterSign = s[i-1];
			}

			char bracketSign = currSign.top();
			if (bracketSign == '+') {
				temp[j++] = letterSign;
			} else {
				temp[j++] = (letterSign == '+') ? '-' : '+';
			}

			temp[j++] = s[i];
		} else if (s[i] == '(') {
			if (i == 0 or s[i-1] == '+') {
				currSign.push(currSign.top());
			} else {
				currSign.push((currSign.top() == '+') ? '-' : '+');
			}
		} else if (s[i] == ')') {
			currSign.pop();
		}
	}

	temp[j] = '\0';

	string retStr(temp);
	return retStr;
}

bool isSimilar(string s1, string s2) {
	bool similar = true;

	string s1Abs = convert(s1);
	string s2Abs = convert(s2);

	map<char,int> m1,m2;
	
	for (int i = 0; i < s1Abs.size(); i += 2) {
		if (s1Abs[i] == '+') {
			m1[s1Abs[i+1]]++;
		} else {
			m1[s1Abs[i+1]]--;
		}
	}

	for (int i = 0; i < s2Abs.size(); i += 2) {
		if (s2Abs[i] == '+') {
			m2[s2Abs[i+1]]++;
		} else {
			m2[s2Abs[i+1]]--;
		}
	}

	for (char i = 'a'; i <= 'z'; ++i) {
		if (m1[i] != m2[i]) {
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		string s1,s2;
		cin >> s1 >> s2;

		string ans = (isSimilar(s1, s2)) ? "YES" : "NO";
		cout << ans << endl;
	}
	return 0;
}