/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence.

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3.
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4.
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1.
*/

class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		if (!nums.size() || nums.size() == 1)
			return nums.size();
		int len = 1;
		int res = -1;
		for (auto i = nums.begin() + 1; i != nums.end(); ++i)
		{
			if (*i > *(i - 1))
				len++;
			else len = 1;
			if (len > res)
				res = len;
		}
		return res;
	}
};