/*
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
 */

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		if (!nums.size())
			return nums;
		// Boyer-Moore majortiy vote algorithm
		vector<int>res;
		int cnt1 = 0, cnt2 = 0, num1 = 0, num2 = 1;
		for (auto num : nums)
		{
			if (num1 == num)
				cnt1++;
			else if (num2 == num)
				cnt2++;
			else if (cnt1 == 0)
			{
				num1 = num;
				cnt1++;
			}
			else if (cnt2 == 0)
			{
				num2 = num;
				cnt2++;
			}
			else
			{
				cnt1--;
				cnt2--;
			}
		}

		cnt1 = cnt2 = 0;
		for (auto num : nums)
		{
			if (num == num1)
				cnt1++;
			else if (num == num2)
				cnt2++;
		}

		if (cnt1 > nums.size() / 3)
			res.push_back(num1);
		if (cnt2 > nums.size() / 3)
			res.push_back(num2);
		return res;
	}
};