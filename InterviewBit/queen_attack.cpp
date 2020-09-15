#include <bits/stdc++.h>

using namespace std;

struct attack_t {
	int left = 0;
	int right = 0;
	int top = 0;
	int bottom = 0;
	int tl_diag = 0;
	int tr_diag = 0;
	int bl_diag = 0;
	int br_diag = 0;
};

vector<vector<int>> _queenAttack(vector<vector<int>> &board) {
	int n = board.size(), m = board[0].size();
	vector<vector<int>> attack_counts(n);
	for (int i = 0; i < n; ++i) {
		attack_counts[i] = vector<int>(m);
	}

	vector<vector<attack_t>> attack_t_vec(n);
	for (int i = 0; i < n; ++i) {
		attack_t_vec[i] = vector<attack_t>(m);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == 0 and j == 0) {
				continue;
			}

			if (i == 0) {
				attack_t_vec[i][j].left = (board[i][j-1]) ? board[i][j-1] : attack_t_vec[i][j-1].left;
			} else if (j == 0) {
				attack_t_vec[i][j].top = (board[i-1][j]) ? board[i-1][j] : attack_t_vec[i-1][j].top;
			} else {
				attack_t_vec[i][j].top = (board[i-1][j]) ? board[i-1][j] : attack_t_vec[i-1][j].top;
				attack_t_vec[i][j].left = (board[i][j-1]) ? board[i][j-1] : attack_t_vec[i][j-1].left;
				attack_t_vec[i][j].tl_diag = (board[i-1][j-1]) ? board[i-1][j-1] : attack_t_vec[i-1][j-1].tl_diag;
			}
		}
	}

	for (int i = n-1; i >= 0; --i) {
		for (int j = m-1; j >= 0; --j) {
			if (i == n-1 and j == m-1) {
				continue;
			}

			if (i == n-1) {
				attack_t_vec[i][j].right = (board[i][j+1]) ? board[i][j+1] : attack_t_vec[i][j+1].right;
			} else if (j == m-1) {
				attack_t_vec[i][j].bottom = (board[i+1][j]) ? board[i+1][j] : attack_t_vec[i+1][j].bottom;
			} else {
				attack_t_vec[i][j].bottom = (board[i+1][j]) ? board[i+1][j] : attack_t_vec[i+1][j].bottom;
				attack_t_vec[i][j].right = (board[i][j+1]) ? board[i][j+1] : attack_t_vec[i][j+1].right;
				attack_t_vec[i][j].br_diag = (board[i+1][j+1]) ? board[i+1][j+1] : attack_t_vec[i+1][j+1].br_diag;
			}
		}
	}

	for (int i = n-2; i >= 0; --i) {
		for (int j = 1; j < m; ++j) {
			attack_t_vec[i][j].bl_diag = (board[i+1][j-1]) ? board[i+1][j-1] : attack_t_vec[i+1][j-1].bl_diag;
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = m-2; j >= 0; --j) {
			attack_t_vec[i][j].tr_diag = (board[i-1][j+1]) ? board[i-1][j+1] : attack_t_vec[i-1][j+1].tr_diag;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			attack_counts[i][j] = attack_t_vec[i][j].left +
									attack_t_vec[i][j].right +
									attack_t_vec[i][j].top +
									attack_t_vec[i][j].bottom +
									attack_t_vec[i][j].tl_diag +
									attack_t_vec[i][j].tr_diag +
									attack_t_vec[i][j].bl_diag +
									attack_t_vec[i][j].br_diag;
		}
	}

	return attack_counts;
}

vector<vector<int>> queenAttack(vector<string> &board) {
	int n = board.size();
	int m = board[0].size();
	vector<vector<int>> board_int(n);
	for (int i = 0; i < n; ++i) {
		board_int[i] = vector<int>(m);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			board_int[i][j] = board[i][j] - '0';
		}
	}

	return _queenAttack(board_int);
}

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<string> board(n);
	for (int i = 0; i < n; ++i) {
		cin >> board[i];
	}

	vector<vector<int>> attack_counts = queenAttack(board);
	for (int i = 0; i < attack_counts.size(); ++i) {
		for (int j = 0; j < attack_counts[i].size(); ++j) {
			cout << attack_counts[i][j] << ' ';
		}

		cout << endl;
	}
	
	return 0;
}