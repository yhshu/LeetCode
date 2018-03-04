/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?
 */

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> dp(target + 1, -1); // dp[i] = i的组合方法数
        dp[0] = 1;
        return comb(nums, target, dp);
    }

    int comb(vector<int> &nums, int target, vector<int> &dp) {
        if (dp[target] != -1)
            return dp[target];
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (target >= nums[i])
                res += comb(nums, target - nums[i], dp);
        }
        dp[target] = res;
        return res;
    }
};