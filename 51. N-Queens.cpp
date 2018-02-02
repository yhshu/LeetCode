/*
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
 */

class Solution {
public:
    vector <vector<string>> solveNQueens(int n) {
        vector <vector<string>> res; // 记录结果，存储多个棋盘
        vector <string> nQueens(n, string(n, '.')); // 当前棋盘
        /*
       flag[0] to flag[n - 1] to indicate if the column had a queen before.
       flag[n] to flag[3 * n - 2] to indicate if the vice diagonal had a queen before.
       flag[3 * n - 1] to flag[5 * n - 3] to indicate if the main diagonal had a queen before.
       */
        vector<int> flag(5 * n - 2, 1); // flag为1表示可用
        solveNQueens(res, nQueens, flag, 0, n);
        return res;
    }

private:
    void solveNQueens(vector <vector<string>> &res, vector <string> &nQueens, vector<int> &flag, int row, int &n) {
        if (row == n) { // row从0开始
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col) {
            if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row]) {
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, flag, row + 1, n); // 下一行
                nQueens[row][col] = '.'; // 回溯，准备尝试下一列
                flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1;
            }
        }
    }
};