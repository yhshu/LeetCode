/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
 */

class Solution {
public:
    int totalNQueens(int n) {
        /*
         * flag[0, n-1] 记录列
         * flag[n, 3n-2] 记录副对角线方向
         * flag[3n-1, 5n-3] 记录主对角线方向
         */
        vector<int> flag(5 * n - 2, 1); // 1表示可用；不要使用vector<bool>，它不是容器
        solveNQueens(flag, 0, n);
        return res;
    }

private:
    int res = 0;

    void solveNQueens(vector<int> &flag, int row, int n) {
        if (row == n) // row从0开始
        {
            res++;
            return;
        }
        for (int col = 0; col != n; ++col) {
            if (flag[col] && flag[n + col + row] && flag[4 * n - 2 - col + row]) {
                flag[col] = flag[n + col + row] = flag[4 * n - 2 - col + row] = 0;
                solveNQueens(flag, row + 1, n);
                flag[col] = flag[n + col + row] = flag[4 * n - 2 - col + row] = 1;
            }
        }
    }
};