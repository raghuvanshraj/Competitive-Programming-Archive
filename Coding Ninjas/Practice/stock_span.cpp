#include <bits/stdc++.h>

using namespace std;

int* stockSpan(int *arr, int n) {

	stack<int> st;
	st.push(0);

	int *output = new int[n]();
	output[0] = 1;

	for (int i = 1; i < n; ++i) {
		
		while (not st.empty() and arr[i] > arr[st.top()]) {
			
			st.pop();
		}

		output[i] = (st.empty()) ? i + 1 : i - st.top();
		st.push(i);
	}

	return output;
}

int main(int argc, char const *argv[]) {
	
	int n;
	cin >> n;
	int *arr = new int [n];
	stack<int> st;
	for (int i = 0; i < n; ++i) {
		
		cin >> arr[i];
	}

	int *output = stockSpan(arr, n);
	for (int i = 0; i < n; ++i) {
		
		cout << output[i] << ' ';
	}

	return 0;
}