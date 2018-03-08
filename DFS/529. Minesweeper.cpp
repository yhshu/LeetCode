/*
Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

If a mine ('M') is revealed, then the game is over - change it to 'X'.
If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.

Example 1:
Input:

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

Output:

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

Example 2:
Input:

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Click : [1,2]

Output:

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

 */

class Solution {
public:
    vector <vector<char>> updateBoard(vector <vector<char>> &board, vector<int> &click) {
        // 一个格子可能的5种状态：未暴露的地雷M；未探索的空白格E；踩中的地雷X；邻近地雷数量；已探索的空白格B
        // 如果选中M，将其转变为X，停止搜索
        // 如果选中E，如果周围有地雷，标注数字，停止搜索
        // 如果选中E，如果周围无地雷，标注B，继续搜索8个邻近格子

        const int m = board.size();
        const int n = board[0].size();
        int x = click[0], y = click[1]; // x∈[0, m-1]  y∈[0, n-1]
        if (board[x][y] == 'M')
            board[x][y] = 'X';
        else if (board[x][y] == 'E') {
            vector <vector<int>> clickSet; // 将被继续搜索的点
            vector<int> v; // 表示坐标
            int cnt = 0; // 附近地雷数量
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int x_new = x + i;
                    int y_new = y + j;
                    vector<int> v = {x_new, y_new};
                    if (x_new < 0 || x_new >= m || y_new < 0 || y_new >= n)
                        continue;
                    switch (board[x_new][y_new]) {
                        case 'M':
                            cnt++;
                            break;
                        case 'E':
                            clickSet.push_back(v);
                            break;
                    }
                }
            }
            if (cnt) // 如果附近有地雷，显示数字
                board[x][y] = cnt + '0';
            else {
                board[x][y] = 'B'; // 附近没有地雷
                for (auto vec :clickSet)
                    updateBoard(board, vec);
            }
        }
        return board;
    }
};