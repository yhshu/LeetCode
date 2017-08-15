/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
 */

public class Solution {
    public int[] twoSum(int[] nums, int target) // 返回两个索引
    {
        int[] ret = new int[2];
        int i, j;
        for (i = 0, j = nums.length - 1; i < j; ) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                ret[0] = i + 1;
                ret[1] = j + 1;
                return ret;
            } else if (sum > target)
                j--;
            else i++;
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
