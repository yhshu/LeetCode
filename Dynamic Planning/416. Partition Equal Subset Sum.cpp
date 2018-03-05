/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
 */

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        // 类似于0-1背包问题
        int sum = 0;
        for (int num:nums)
            sum += num;
        if ((sum & 1) == 1) // 奇数
            return false;
        sum /= 2; // 选出一部分数能得到sum/2 即可返回true

        const int size = nums.size();
        if (size == 0)return true;
        else if (size == 1)return false;

        bool dp[size + 1][sum + 1]; // dp[i][j]表示前i个数能否凑出j
        memset(dp, false, sizeof(dp));

        for (int i = 0; i <= size; i++) {
            dp[i][0] = true; // 前i个数全不选
        }

        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= sum; j++) {
                dp[i][j] = dp[i - 1][j]; // 不选第i个
                if (j >= nums[i - 1]) {
                    dp[i][j] = (dp[i][j] || dp[i - 1][j - nums[i - 1]]); // 选第i个
                }
            }
        }
        return dp[size][sum];
    }
};