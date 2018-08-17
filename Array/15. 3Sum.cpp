/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		const int size = nums.size();
		for (int i = 0; i < size - 2; i++) {
			if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) { // 跳过相同的数字
				int low = i + 1, high = size - 1, sum = 0 - nums[i];
				while (low < high) {
					if (nums[low] + nums[high] == sum) {
						vector<int> vec;
						vec.push_back(nums[i]);
						vec.push_back(nums[low]);
						vec.push_back(nums[high]);
						res.push_back(vec);
						while (low < high && nums[low] == nums[low + 1]) low++; // 跳过相同数字
						while (low < high && nums[high] == nums[high - 1]) high--;
						low++;
						high--;
					} else if (nums[low] + nums[high] < sum) low++;
					else high--;
				}
			}
		}
		return res;
	}
};