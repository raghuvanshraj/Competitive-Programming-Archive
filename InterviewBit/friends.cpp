#include <bits/stdc++.h>

using namespace std;

void dfs(int **graph, int s, int pos, bool *is_visited, int n) {
	if (pos == 3) {
		return;
	}

	is_visited[s] = true;
	for (int i = 2; i < n+2; ++i) {
		if (graph[s][i] and not is_visited[i]) {
			dfs(graph, i, pos+1, is_visited, n);
		}
	}
}

int count_groups(int **graph, int n) {
	bool *is_visited = new bool[n+2]();
	int count = 0;
	for (int i = 2; i < n+2; ++i) {
		if (not is_visited[i]) {
			dfs(graph, i, 0, is_visited, n);
			count++;
		}
	}

	return count;
}

int friends(int n) {
	int **graph = new int*[n+2]();
	for (int i = 0; i < n+2; ++i) {
		graph[i] = new int[n+2]();
	}

	for (int i = 2; i < n+2; ++i) {
		for (int j = i * 2; j < n+2; j += i) {
			graph[i][j] = 1;
			graph[j][i] = 1;
		}
	}

	return count_groups(graph, n);
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	cout << friends(n);
	
	return 0;
}