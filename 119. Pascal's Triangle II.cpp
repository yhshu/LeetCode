/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        int triangle[rowIndex + 10][rowIndex + 10] = {0};
        for (int i = 0; i <= rowIndex; i++)//第i行，从0开始
        {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    triangle[i][j] = 1;
                if (i > 1 && j > 0)
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
        }
        for (int i = 0; i <= rowIndex; i++) {
            res.push_back(triangle[rowIndex][i]);
        }
        return res;
    }

};