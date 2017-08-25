/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
class Solution {
    public int singleNumber(int[] nums) {
        int res = 0;
        for (int i = 0; i != nums.length; ++i) {
            res ^= nums[i];//位运算具有可交换性
        }
        return res;
    }
}