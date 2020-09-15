#include <bits/stdc++.h>
#define MAX 1024

using namespace std;

int main(int argc, char const *argv[]) {
	
	int n, k, x;
	cin >> n >> k >> x;
	int *elts = new int[MAX]();
	while (n--) {
		
		int elt;
		cin >> elt;
		elts[elt]++;
	}

	int *temp = new int[MAX]();
	while (k--) {
		
		bool convertFirst = true;
        memset(temp, 0, sizeof(int) * MAX);
		for (int i = 0; i < MAX; ++i) {
			
			int countRemoved;
			if (elts[i] > 0) {
				
				if (elts[i] % 2 == 0) {
					
					countRemoved = elts[i] / 2;
				} else {

					if (convertFirst) {
						
						countRemoved = elts[i] / 2 + 1;
					} else {

						countRemoved = elts[i] / 2;
					}

					convertFirst = not convertFirst;
				}

				temp[i] -= countRemoved;
				temp[i^x] += countRemoved;
			}
		}

		for (int i = 0; i < MAX; ++i) {
			
			elts[i] += temp[i];
		}
	}

	for (int i = MAX-1; i >= 0; --i) {
		
		if (elts[i] > 0) {
			
			cout << i << ' ';
			break;
		}
	}

	for (int i = 0; i < MAX; ++i) {
		
		if (elts[i] > 0) {
			
			cout << i;
			break;
		}
	}

	return 0;
}