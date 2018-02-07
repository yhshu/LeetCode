/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/

class Solution {
public:
    int maximalSquare(vector <vector<char>> &matrix) {
        if (matrix.empty())
            return 0;
        int m = matrix.size(); // 行数
        int n = matrix[0].size(); // 列数
        vector <vector<int>> edge(m, vector<int>(n, 0));
        int maxEdge = 0;
        for (int j = 0; j < n; ++j) { // 第一行
            edge[0][j] = matrix[0][j] - '0';
            maxEdge = max(maxEdge, edge[0][j]);
        }
        for (int i = 1; i < m; ++i) { // 第一列
            edge[i][0] = matrix[i][0] - '0';
            maxEdge = max(maxEdge, edge[i][0]);
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    edge[i][j] = min(edge[i - 1][j - 1], min(edge[i][j - 1], edge[i - 1][j])) + 1;
                    maxEdge = max(maxEdge, edge[i][j]);
                }
            }
        }
        return maxEdge * maxEdge;
    }
};