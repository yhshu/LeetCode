/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
 */

class Solution {
public:
    bool exist(vector <vector<char>> &board, string word) {
        const int m = board.size();
        const int n = board[0].size();
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (exist(board, x, y, word, 0))
                    return true;
            }
        }
        return false;
    }

private:
    bool exist(vector <vector<char>> &board, int x, int y, const string &word, int step) {
        if (step == word.size())
            return true;
        if (x < 0 || y < 0 || x == board.size() || y == board[0].size() || board[x][y] != word[step])
            return false;
        board[x][y] ^= 128; // vis 标记：C++ char类型长度是1字节，大小写字母的ASCII码的最高位均为0
        bool existFlag = exist(board, x, y + 1, word, step + 1) || exist(board, x + 1, y, word, step + 1) ||
                         exist(board, x - 1, y, word, step + 1) || exist(board, x, y - 1, word, step + 1);
        board[x][y] ^= 128;
        return existFlag;
    }
};