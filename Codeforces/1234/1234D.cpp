/**
 *    author:	vulkan
 *    created:	28.10.2019 07:18:41 AM
**/
#include <bits/stdc++.h>
#define MAX_CHARS 26

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	set<int> pos[MAX_CHARS];
	for (int i = 0; i < s.size(); ++i) {
		pos[s[i] - 'a'].insert(i);
	}

	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int p;
			char c;
			cin >> p >> c;
			p--;

			pos[s[p] - 'a'].erase(p);
			s[p] = c;
			pos[s[p] - 'a'].insert(p);
		} else if (type == 2) {
			int l, r;
			cin >> l >> r;
			l--;
			r--;

			int ans = 0;
			for (int i = 0; i < MAX_CHARS; ++i) {
				auto it = pos[i].lower_bound(l);
				if (it != pos[i].end() and * it <= r) {
					ans++;
				}
			}

			cout << ans << endl;
		}
	}

	return 0;
}