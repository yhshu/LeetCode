/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
 */

class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1] = {0}; // dp[i]表示凑出i最少所需的完全平方数个数
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int MIN = INT_MAX;
            int j = 1;
            while (i - j * j >= 0) {
                MIN = min(MIN, dp[i - j * j] + 1);
                ++j;
            }
            dp[i] = MIN;
        }
        return dp[n];
    }
};