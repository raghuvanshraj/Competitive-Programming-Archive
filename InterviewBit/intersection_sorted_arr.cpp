#include <bits/stdc++.h>

using namespace std;

vector<int> intersect(const vector<int> &a, const vector<int> &b) {
    int i = 0, j = 0;
    int x = a.size(), y = b.size();
    vector<int> intersection;
    while (i < x and j < y) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            intersection.push_back(a[i]);
            i++;
            j++;
        }
    }

    return intersection;
}

int main(int argc, char const *argv[]) {
	int x,y;
	cin >> x >> y;
	vector<int> a(x), b(y);
	for (int i = 0; i < x; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < y; ++i) {
		cin >> b[i];
	}

	vector<int> intersection = intersect(a,b);
	for (int i = 0; i < intersection.size(); ++i) {
		cout << intersection[i] << ' ';
	}
	return 0;
}