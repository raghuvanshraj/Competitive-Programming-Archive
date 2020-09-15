/**
 *    author:	vulkan
 *    created:	15.10.2019 05:55:22 PM
**/
#include <bits/stdc++.h>

using namespace std;

int get_cost(int *order, int **color_costs, int n, int color_order[]) {
	// cout << "get_cost" << endl;

	int curr_cost = 0;
	for (int i = 0; i < n; ++i) {
		// cout << order[i] << ' ' << color_order[i] << endl;
		curr_cost += color_costs[order[i]][color_order[i % 3]];
	}

	return curr_cost;
}

void dfs(int start, vector<int> vertices[], bool *is_visited, vector<int> &order_vec) {
	// cout << "dfs" << endl;

	is_visited[start] = true;
	order_vec.push_back(start);
	// cout << start << ' ';
	// cout.flush();
	int n = vertices[start].size();
	for (int i = 0; i < n; ++i) {
		if (not is_visited[vertices[start][i]]) {
			is_visited[vertices[start][i]] = true;
			dfs(vertices[start][i], vertices, is_visited, order_vec);
		}
	}
}

int* get_order(vector<int> vertices[], int n) {
	// cout << "get_order" << endl;

	int *order = new int[n]();
	vector<int> order_vec;
	for (int i = 0; i < n; ++i) {
		int curr_size = vertices[i].size();
		if (curr_size == 1) {
			bool *is_visited = new bool[n]();
			dfs(i, vertices, is_visited, order_vec);

			break;
		}
	}

	// for (int i = 0; i < order_vec.size(); ++i) {
	// 	cout << order_vec[i] << ' ';
	// }
	// cout << endl;

	for (int i = 0; i < n; ++i) {
		order[i] = order_vec[i];
	}

	return order;
}

pair<int, int*> get_solution(vector<int> vertices[], int **color_costs, int n) {
	// cout << "get_solution" << endl;

	int *colors = new int[n]();
	int *order = get_order(vertices, n);
	// for (int i = 0; i < n; ++i) {
	// 	cout << order[i] << ' ';
	// }
	// cout << endl;
	int min_cost = INT_MAX;
	int best_order[3];
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == j) {
				continue;
			}

			for (int k = 0; k < 3; ++k) {
				if (j == k or i == k) {
					continue;
				}

				int color_order[3] = {i, j, k};
				// for (int i = 0; i < 3; ++i) {
				// 	cout << color_order[i] << ' ';
				// }
				// cout << endl;
				int curr_cost = get_cost(order, color_costs, n, color_order);
				// cout << "f" << endl;
				// for (int i = 0; i < 3; ++i) {
				// 	cout << color_order[i] << ' ';
				// }
				// cout << endl;
				if (min_cost > curr_cost) {
					min_cost = curr_cost;
					for (int i = 0; i < 3; ++i) {
						best_order[i] = color_order[i];
					}
				}
			}
		}
	}

	// for (int i = 0; i < 3; ++i) {
	// 	cout << best_order[i] << ' ';
	// }
	// cout << endl;

	int *best_order_scaled = new int[n]();
	for (int i = 0; i < n; ++i) {
		best_order_scaled[i] = best_order[i % 3];
	}

	// for (int i = 0; i < n; ++i) {
	// 	cout << best_order_scaled[i] << ' ';
	// }
	// cout << endl;

	return {min_cost, best_order_scaled};
}

int main(int argc, char const *argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> vertices[n];
	int *degrees = new int[n]();
	int **color_costs = new int*[n];
	for (int i = 0; i < n; ++i) {
		color_costs[i] = new int[3]();
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> color_costs[j][i];
		}
	}

	int m = n - 1;
	bool flag = true;
	while (m--) {
		int i, j;
		cin >> i >> j;
		vertices[i - 1].push_back(j - 1);
		vertices[j - 1].push_back(i - 1);
		degrees[i - 1]++;
		degrees[j - 1]++;

		if (degrees[i - 1] >= 3 or degrees[j - 1] >= 3) {
			flag = false;
		}
	}

	delete [] degrees;

	if (not flag) {
		cout << "-1";
	} else {
		pair<int, int*> solution = get_solution(vertices, color_costs, n);
		cout << solution.first << endl;
		for (int i = 0; i < n; ++i) {
			cout << solution.second[i] + 1 << ' ';
		}
	}

	return 0;
}