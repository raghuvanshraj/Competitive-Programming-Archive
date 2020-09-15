#include <bits/stdc++.h>
#define pb(x) push_back(x)

using namespace std;

pair<vector<int>,int> kadane(vector<int> arr) {
	int bestSum = INT_MIN;
	int currSum = 0;
	vector<int> bestSequence;
	vector<int> currSequence;
	for (int i = 0; i < arr.size(); ++i) {
		currSum += arr[i];
		currSequence.pb(arr[i]);
		if (bestSum < currSum) {
			bestSum = currSum;
			bestSequence = currSequence;
		}
		if (currSum < 0) {
			currSum = 0;
			currSequence.clear();
		}
	}

	pair<vector<int>,int> bestPair;
	reverse(bestSequence.begin(), bestSequence.end());
	bestPair.first = bestSequence;
	bestPair.second = bestSum;

	return bestPair;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> arr[2];
		for (int i = 0; i < n; ++i) {
			int elt;
			cin >> elt;
			arr[i % 2].pb(elt);
		}

		pair<vector<int>,int> pair1 = kadane(arr[0]);
		pair<vector<int>,int> pair2 = kadane(arr[1]);

		pair<vector<int>,int> bestPair;
		if (pair1.second > pair2.second) {
			bestPair = pair1;
		} else if (pair1.second < pair2.second) {
			bestPair = pair2;
		} else {
			vector<int> seq1 = pair1.first;
			vector<int> seq2 = pair2.first;
			if (seq1.size() > seq2.size()) {
				bestPair = pair1;
			} else if (seq1.size() < seq2.size()) {
				bestPair = pair2;
			} else {
				int i = 0;
				while ((seq1[i] == seq2[i]) and (i < seq1.size()) and (i < seq2.size())) {
					i++;
				}

				if (seq1[i] > seq2[i]) {
					bestPair = pair1;
				} else {
					bestPair = pair2;
				}
			}
		}

		vector<int> bestSequence = bestPair.first;
		for (int i = 0; i < bestSequence.size(); ++i) {
			cout << bestSequence[i];
		}

		cout << endl;
	}
	return 0;
}