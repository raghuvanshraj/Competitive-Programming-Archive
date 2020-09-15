#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int> &arr_original) {
    int llap = 2;
    int n = arr_original.size();
    if (n <= 2) {
        return n;
    }
    
    int dp[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        dp[i][n-1] = 2;
    }
    
    vector<int> arr(arr_original);
    sort(arr.begin(), arr.end());

    for (int j = n-2; j >= 1; --j) {
        int i = j-1, k = j+1;
        while (i >= 0 and k < n) {
            if (arr[i] + arr[k] > 2 * arr[j]) {
                dp[i][j] = 2;
                i--;
            } else if (arr[i] + arr[k] < 2 * arr[j]) {
                k++;
            } else {
                dp[i][j] = 1 + dp[j][k];
                llap = max(llap, dp[i][j]);
                i--;
                k++;
            }
        }

        while (i >= 0) {
            dp[i][j] = 2;
            i--;
        }
    }

    return llap;
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << solve(arr);
	
	return 0;
}