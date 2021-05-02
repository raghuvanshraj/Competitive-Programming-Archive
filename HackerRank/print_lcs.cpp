/**
 *    author:	vulkan
 *    created:	02.09.2019 07:21:56 PM
**/
#include <bits/stdc++.h>

using namespace std;

struct dp_t {
	int len = 0;
	vector<int> lcs;
};

vector<int> find_lcs(int a[], int n, int b[], int m) {

}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int a[n], b[m];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}

	vector<int> lcs = find_lcs(a, n, b, m);
	int lcs_size = lcs.size();
	for (int i = 0; i < lcs_size; ++i) {
		cout << lcs[i] << ' ';
	}

	return 0;
}