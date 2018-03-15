/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
 */

class Solution {
public:
    void solveSudoku(vector <vector<char>> &board) {
        if (board.size() == 0)
            return;
        solve(board);
    }

    bool solve(vector <vector<char>> &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') { // '.'是待填
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            board[i][j] = '.'; // 回溯
                        }
                    }
                    return false; // board[i][j]无论填哪个数字都无法完成数独
                }
            }
        }
        return true;
    }

    bool isValid(const vector <vector<char>> &board, const int x, const int y, const char &c) {
        for (int i = 0; i < 9; i++) {
            if (isdigit(board[i][y]) && board[i][y] == c) // 检查行
                return false;
            if (isdigit(board[x][i]) && board[x][i] == c) // 检查列
                return false;
            if (isdigit(board[3 * (x / 3) + i / 3][3 * (y / 3) + i % 3]) &&
                board[3 * (x / 3) + i / 3][3 * (y / 3) + i % 3] == c) // 检查九宫格
                return false;
        }
        return true;
    }
};