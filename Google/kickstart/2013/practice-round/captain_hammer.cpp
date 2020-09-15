/**
 *    author:	vulkan
 *    created:	27.10.2019 02:24:43 PM
**/
#include <bits/stdc++.h>
#define G 9.8
#define ACC 1e-9

using namespace std;

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		double v, d;
		cin >> v >> d;
		double ratio = pow(v, 2) / G;
		double start = 0, end = M_PI / 2;
		while (start <= end) {
			double mid = (start + end) / 2;
			double curr_distance = ratio * sin(2 * mid);
			if (abs(curr_distance - d) <= ACC) {
				double ans = mid * ((double)180 / M_PI);
				if (ans > 45) {
					ans = 90.0 - ans;
				}

				printf("Case #%d: %.7f\n", i + 1, ans);
				break;
			} else if (curr_distance > d) {
				start = mid;
			} else if (curr_distance < d) {
				end = mid;
			}
		}
	}

	return 0;
}