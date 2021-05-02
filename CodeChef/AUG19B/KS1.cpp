#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll num_triplets(ll *arr, ll n) {
	ll xor_arr[n] = {0};
	map<ll,vector<ll>> ranges;
	xor_arr[0] = arr[0];
	ranges[xor_arr[0]].push_back(0);
	for (ll i = 1; i < n; ++i) {
		xor_arr[i] = arr[i] ^ xor_arr[i-1];
		ranges[xor_arr[i]].push_back(i);
	}

	ll ans = 0;
	for (auto it = ranges.begin(); it != ranges.end(); ++it) {
		vector<ll> curr_vector = it->second;
		ll m = curr_vector.size();
		sort(curr_vector.begin(), curr_vector.end());
		ll i = 0, j = m-1;
		while (i <= j) {
			ans += (ll)(j - i) * (curr_vector[j] - curr_vector[i]);
			i++;
			j--;
		}

		ans -= (m * (m-1) / 2);
	}

	for (ll i = 0; i < n; ++i) {
		if (xor_arr[i] == 0) {
			ans += (ll)i;
		}
	}

	return ans;
}

int main(int argc, char const *argv[]) {
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll arr[n] = {0};
		for (ll i = 0; i < n; ++i) {
			cin >> arr[i];
		}

		cout << num_triplets(arr, n) << endl;
	}
	
	return 0;
}