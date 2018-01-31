/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.
 */

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp{0, 0, 1, 2, 4, 6, 9};
        for (int i = 7; i <= n; i++) {
            dp.push_back(3 * dp[i - 3]);
        }
        return dp[n];
    }
};