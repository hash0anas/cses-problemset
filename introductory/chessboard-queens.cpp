#include <bits/stdc++.h>

using namespace std;

int answer = 0;
vector<string> board;

bool is_safe(int row, int col) {
    // check the column.
    for(int i = 0; i < 8; ++i) {
        if(board[i][col] == 'Q') return false;
    }
    // check the diagonal.
    for(int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
       if(board[i][j] == 'Q') return false; 
    }
    // check the off-diagonal.
    for(int i = row, j = col; i >= 0 && j < 8; --i, ++j) {
       if(board[i][j] == 'Q') return false; 
    }
    return true;
}

void backtrack(int row) {
    if(row == 8) {
        ++answer;
        return;
    }
    // Look for a valid column.
    for(int col = 0; col < 8; ++col) {
        if(board[row][col] == '.' && is_safe(row, col)) {
            board[row][col] = 'Q';
            backtrack(row + 1);
            board[row][col] = '.'; // backtrack.
        }
    }
}

int main() {
    board = vector<string>(8, string(8, '.'));
    for(string &row : board) {
        cin >> row;
    }
    backtrack(0);
    cout << answer << endl;
}