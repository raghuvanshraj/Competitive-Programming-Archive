/**
 *    author:	vulkan
 *    created:	10.04.2020 12:23:29 PM
**/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define MOD 1000000007
#define MAX_BITS 32

#define SET_ARR(arr,n,val) for (int i = 0; i < n; ++i) arr[i] = val
#define SET_ARR2D(arr,n,m,val) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) arr[i][j] = val
#define INPUT_ARR(arr,n) for (int i = 0; i < n; ++i) cin >> arr[i];
#define INPUT_ARR2D(arr,n,m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
#define PRINT_ARR(arr,n) for (int i = 0; i < n; ++i) cout << arr[i] << ' '; cout << endl
#define PRINT_ARR2D(arr,n,m) for (int i = 0; i < n; ++i) { for (int j = 0; j < m; ++j) cout << arr[i][j] << ' '; cout << endl; }

#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using max_heap = priority_queue<T>;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<U>::value, U>::type
    >
pair<T, U> operator+(const pair<T, U> &a, const pair<T, U> &b) {
	return {a.first + b.first, a.second + b.second};
}

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<U>::value, U>::type
    >
pair<T, U> operator-(const pair<T, U> &a, const pair<T, U> &b) {
	return {a.first - b.first, a.second - b.second};
}

template <
    typename T,
    typename = typename enable_if<is_arithmetic<T>::value, T>::type,
    typename U,
    typename = typename enable_if<is_arithmetic<U>::value, U>::type,
    typename V,
    typename = typename enable_if<is_arithmetic<V>::value, V>::type
    >
pair<T, U> operator*(const V &a, const pair<T, U> &b) {
	return {a * b.first, a * b.second};
}

struct trie_node_t {
	vector<trie_node_t*> child = vector<trie_node_t*>(2, NULL);
};

class trie_t {
	trie_node_t *node;
public:
	trie_t(vector<ll> &arr);
	void build(ll elt);
	ll find_xor(ll q);
};

trie_t::trie_t(vector<ll> &arr) {
	this->node = new trie_node_t();
	for (ll x : arr) {
		this->build(x);
	}
}

void trie_t::build(ll elt) {
	ll curr_elt = elt;
	vector<int> bin_elt(MAX_BITS);
	for (int i = 31; i >= 0; --i) {
		bin_elt[i] = (curr_elt & 1);
		curr_elt /= 2LL;
	}

	trie_node_t *curr = this->node;
	for (int i = 0; i < MAX_BITS; ++i) {
		if (not curr->child[bin_elt[i]]) {
			curr->child[bin_elt[i]] = new trie_node_t();
		}

		curr = curr->child[bin_elt[i]];
	}
}

ll trie_t::find_xor(ll q) {
	vector<int> bin_q(MAX_BITS);
	for (int i = 31; i >= 0; --i) {
		bin_q[i] = (q & 1);
		q /= 2LL;
	}

	trie_node_t *curr = this->node;
	ll val = 0;
	for (int i = 0; i < MAX_BITS; ++i) {
		int bit = bin_q[i];
		val *= 2LL;
		if (curr->child[not bit]) {
			curr = curr->child[not bit];
			val += 1LL;
		} else if (curr->child[bit]) {
			curr = curr->child[bit];
		} else {
			break;
		}
	}

	return val;
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<ll> arr(n);
	INPUT_ARR(arr, n);
	trie_t trie(arr);

	int m;
	cin >> m;
	while (m--) {
		ll q;
		cin >> q;
		cout << trie.find_xor(q) << endl;
	}

	return 0;
}