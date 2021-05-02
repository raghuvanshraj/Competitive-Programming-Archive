/**
 *    author:	vulkan
 *    created:	19.06.2020 08:38:44 PM
**/
#include <bits/stdc++.h>

using namespace std;

class TreeAncestor {
	vector<vector<int>> dp;
public:
	TreeAncestor(int n, vector<int>& parent) {
		vector<vector<int>> dp(n, vector<int>(32));
		for (int i = 0; i <= n - 1; ++i) {
			dp[i][0] = parent[i];
			for (int j = 1; j <= 31; ++j) {
				if (dp[i][j - 1] == -1) {
					dp[i][j] = -1;
				} else {
					dp[i][j] = dp[dp[i][j - 1]][j - 1];
				}
			}
		}

		swap(this->dp, dp);
	}

	int getKthAncestor(int node, int k) {
		for (int i = 0; i <= 31; ++i) {
			if (k & (1 << i)) {
				node = this->dp[node][i];
				if (node == -1) {
					return -1;
				}
			}
		}

		return node;
	}
};

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> parent(n);
	for (int i = 0; i <= n - 1; ++i) {
		cin >> parent[i];
	}

	TreeAncestor *obj = new TreeAncestor(n, parent);
	int t;
	cin >> t;
	while (t--) {
		int node, k;
		cin >> node >> k;
		cout << obj->getKthAncestor(node, k) << endl;
	}

	return 0;
}