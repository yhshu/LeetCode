/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 */

class Solution {
public:
    int rob(vector<int> &nums) {
        const int size = nums.size();
        if (size < 2) // size 为0或1
            return size ? nums[0] : 0;
        return max(rob(nums, 0, size - 2), rob(nums, 1, size - 1));
    }

    int rob(vector<int> &nums, int left, int right) {
        int even = 0, odd = 0;
        for (int i = left; i <= right; i++) {
            if ((i - left) % 2 == 0)
                even = max(even + nums[i], odd);
            else
                odd = max(odd + nums[i], even);
        }
        return max(even, odd);
    }
};