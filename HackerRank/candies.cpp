/**
 *    author:    raghuvanshraj
 *    created:    02.09.2019 12:39:00 PM
**/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int left[n];
    for (int i = 0; i < n; ++i) {
        left[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i-1]) {
            left[i] = left[i-1] + 1;
        }
    }

    int right[n];
    for (int i = 0; i < n; ++i) {
        right[i] = 1;
    }
    for (int i = n-2; i >= 0; --i) {
        if (arr[i] > arr[i+1]) {
            right[i] = right[i+1] + 1;
        }
    }

    long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (long)max(left[i], right[i]);
    }

    cout << ans;
    
    return 0;
}