/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.

 */
class Solution {
public:
    int maximalRectangle(vector <vector<char>> &matrix) {
        if (matrix.empty())
            return 0;
        const int m = matrix.size(); // 行数
        const int n = matrix[0].size(); // 列数
        int maxArea = 0;
        int left[n], right[n], height[n];
        fill_n(left, n, 0); // 当前点所在矩阵的左边界
        fill_n(right, n, n); // 当前点所在矩阵的右边界
        fill_n(height, n, 0); // 当前点高度
        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                    left[j] = max(left[j], cur_left); // left[j]是之前行的约束，cur_left是当前行的约束
                } else {
                    height[j] = 0;
                    left[j] = -1;
                    cur_left = j + 1;
                }
            }
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], cur_right);
                else {
                    right[j] = n + 1;
                    cur_right = j; // 注意不是j-1
                }
            }
            for (int j = 0; j < n; ++j)
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
        }
        return maxArea;
    }
};