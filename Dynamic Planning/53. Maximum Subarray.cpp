/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int maxSum = nums[0]; // 找到的连续子数组至少包含一个数
        int curSum = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if (curSum >= 0)
                curSum += nums[i];
            else curSum = nums[i];
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};