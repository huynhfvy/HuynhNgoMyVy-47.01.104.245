#include <iostream>
#include <vector>
using namespace std;

int count = 0;

bool isSafe(vector<vector<int> >& board, int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        if (board[i][col])
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j])
            return false;
    }

    return true;
}

void solveNQueens(vector<vector<int> >& board, int row, int N) {
    if (row == N) {
        count++;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            solveNQueens(board, row + 1, N);
            board[row][col] = 0;
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<int> > board(N, vector<int>(N, 0));
    solveNQueens(board, 0, N);

    cout << count << endl;

    return 0;
}
