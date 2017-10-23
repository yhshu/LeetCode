/*
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
 */

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		// Boyer-Moore majortiy vote algorithm
		int len = nums.size(), count = 0, major;
		for (int i = 0; i < len; i++)
		{
			if (!count)
			{
				major = nums[i];
				count++;
			}
			else if (nums[i] == major)
				count++;
			else count--;
		}
		return major;
	}
};