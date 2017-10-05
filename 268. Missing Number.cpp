/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
 */

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int i = 0;
		int res = nums.size();
		for (auto num : nums)
		{
			res ^= num;
			res ^= (i++);
		}
		return res;
	}
};