/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3.
Output: 5
Explanation:

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
 */


class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int S) {
        unordered_map<int, int> dp; // dp[sum]=cnt 表示代数和为sum的情况有cnt种
        dp[0] = 1;
        for (int num : nums) {
            unordered_map<int, int> dp_new;
            for (auto assign : dp) {
                int sum = assign.first, cnt = assign.second;
                dp_new[sum + num] += cnt;
                dp_new[sum - num] += cnt;
            }
            dp = dp_new;
        }
        return dp[S];
    }
};