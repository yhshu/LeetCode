/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
 */

class Solution {
public:
    void DFS(vector <vector<char>> &board, int i, int j) {
        if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 'O') {
            board[i][j] = '1'; // vis可免去
            DFS(board, i - 1, j);
            DFS(board, i + 1, j);
            DFS(board, i, j - 1);
            DFS(board, i, j + 1);
        }
    }

    void solve(vector <vector<char>> &board) {
        // 首先将在边缘的O以及与它们相连的O全改为1
        // 然后将剩余的所有O，即被X完全包围的所有O改为X
        // 最后将所有1改回O
        const int m = board.size();
        if (!m)return;
        const int n = board[0].size();
        for (int i = 0; i < m; i++) {
            DFS(board, i, 0);
            DFS(board, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            DFS(board, 0, j);
            DFS(board, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
    }
};