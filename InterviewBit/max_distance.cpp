/**
 *    author:   vulkan
 *    created:  13.01.2020 05:20:16 PM
**/
#include <bits/stdc++.h>

using namespace std;

int maximumGap(const vector<int> &const_arr) {
    vector<int> arr = const_arr;
    int n = arr.size();
    map<int, pair<int, int>> indices;
    for (int i = 0; i < n; ++i) {
        if (indices.find(arr[i]) == indices.end()) {
            indices[arr[i]] = {i, i};
        } else {
            pair<int, int> curr_pair = indices[arr[i]];
            indices[arr[i]] = {min(curr_pair.first, i), max(curr_pair.second, i)};
        }
    }

    sort(arr.begin(), arr.end());
    int min_idx = n - 1;
    int max_dist = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (min_idx > indices[arr[i]].first) {
            min_idx = indices[arr[i]].first;
        }

        max_dist = max(max_dist, indices[arr[i]].second - min_idx);
    }

    return (max_dist >= 0) ? max_dist : -1;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << maximumGap(arr);

    return 0;
}