#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> ans;

bool colSafe(vector<vector<int>> &board, int row, int col, int n) {
    for (int i = 0; i < n; i++) {
        if (board[i][col] == 1 and i != row) {
            return false;
        }
    }
    
    return true;
}

bool diagonalsSafe(vector<vector<int>> &board, int row, int col, int n) {
    int i, j;

    i = row+1;
    j = col+1;
    while (i < n and j < n) {
        if (board[i][j] == 1) {
            return false;
        }

        i++;
        j++;
    }

    i = row+1;
    j = col-1;
    while (i < n and j >= 0) {
        if (board[i][j] == 1) {
            return false;
        }

        i++;
        j--;
    }

    i = row-1;
    j = col+1;
    while (i >= 0 and j < n) {
        if (board[i][j] == 1) {
            return false;
        }

        i--;
        j++;
    }

    i = row-1;
    j = col-1;
    while (i >= 0 and j >= 0) {
        if (board[i][j] == 1) {
            return false;
        }

        i--;
        j--;
    }
    
    return true;
}

bool isSafe(vector<vector<int>> &board, int row, int col, int n) {
    if (
        colSafe(board, row, col, n) 
        and diagonalsSafe(board, row, col, n)
    ) {
  //       for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << board[i][j] << ' ';
        //     }

        //     cout << endl;
        // }

        // cout << row << ' ' << col << endl;

        // cout << endl << endl;
        // cout << row << ' ' << col << endl;
        return true;
    }
}

void _solveNQueens(vector<vector<int>> &board, int row, int n) {
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << board[i][j] << ' ';
    //     }

    //     cout << endl;
    // }

    // cout << endl << endl;
    if (row == n) {
        // cout << "done";
        // for (int i = 0; i < n; ++i) {
        // 	for (int j = 0; j < n; ++j) {
        // 		cout << board[i][j] << ' ';
        // 	}
        // 	cout << endl;
        // }

        // cout << endl << endl;
        ans.push_back(board);
        return;
    }
    
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            // cout << "d";
            board[row][col] = 1;
            _solveNQueens(board, row+1, n);
            board[row][col] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<string>> stringAns;
    if (A == 2 or A == 3) {
        return stringAns;
    }
    
    // int **board = new int*[A]();
    // for (int i = 0; i < A; i++) {
    //     board[i] = new int[A]();
    // }

    vector<vector<int>> board(A);
    for (int i = 0; i < A; ++i) {
    	board[i] = vector<int>(A);
    }
    
    _solveNQueens(board, 0, A);

    // for (int i = 0; i < ans.size(); ++i) {
    // 	for (int row = 0; row < A; ++row) {
    // 		for (int col = 0; col < A; ++col) {
    // 			cout << ans[i][row][col] << ' ';
    // 		}
    // 		cout << endl;
    // 	}

    // 	cout << endl << endl;
    // }
    
    stringAns = vector<vector<string>>(ans.size());
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < A; j++) {
            string row = "";
            for (int k = 0; k < A; k++) {
                if (ans[i][j][k] == 1) {
                    row = row + "Q";
                } else {
                    row = row + ".";
                }
            }

            // cout << row << endl;
            
            stringAns[i].push_back(row);
        }
    }

    // for (int i = 0; i < stringAns.size(); i++) {
    //     for (int j = 0; j < stringAns[i].size(); ++j) {
    //         cout << stringAns[i][j];
    //     }

    //     cout << endl;
    // }
}


int main(int argc, char const *argv[]) {
	int n;
	cin >> n;
	vector<vector<string>> stringAns = solveNQueens(n);
	// cout << "done";

	for (int i = 0; i < stringAns.size(); i++) {
    	for (int j = 0; j < stringAns[i].size(); ++j) {
    		cout << stringAns[i][j];
    	}

    	cout << endl;
    }

	return 0;
}