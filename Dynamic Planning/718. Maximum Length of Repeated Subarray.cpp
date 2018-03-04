/*
Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:
Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation:
The repeated subarray with maximum length is [3, 2, 1].
Note:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
 */

class Solution {
public:
    int findLength(vector<int> &A, vector<int> &B) {
        int res = 0;
        const int Asize = A.size();
        const int Bsize = B.size();
        int dp[Asize + 1][Bsize + 1] = {0}; // dp[i][j] 表示A前i个数字与B前j个数字的最大相同子数组的长度
        for (int i = 0; i <= Asize; i++) {
            for (int j = 0; j <= Bsize; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    res = max(dp[i][j], res);
                    if (res >= max(i, j)) // res 不会超过max(i,j)
                        continue;
                }
            }
        }
        return res;
    }
};