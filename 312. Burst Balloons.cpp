/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
 */

class Solution {
public:
    int maxCoins(vector<int> &inums) {
        int nums[inums.size() + 2]; // 前后加上1
        int n = 1;
        for (int num:inums) {
            if (num > 0) // inums中的0被丢弃
                nums[n++] = num;
        }
        nums[0] = nums[n++] = 1; // 前后加上1

        int dp[n][n] = {}; // dp[i][j]表示[i,j]中可获取的maxCoins
        // 二维数组初始化为0 = {}
        for (int len = 2; len < n; len++) {
            for (int left = 0; left + len < n; left++) {
                int right = left + len;
                for (int i = left + 1; i < right; i++) {
                    dp[left][right] = max(dp[left][right],
                                          dp[left][i] + dp[i][right] + nums[left] * nums[i] * nums[right]);
                    // 气球i是(left,right)中最后一个击破的
                }
            }
        }
        return dp[0][n - 1];
    }
};