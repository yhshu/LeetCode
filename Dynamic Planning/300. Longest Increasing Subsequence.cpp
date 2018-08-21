/*
 * Given an unsorted array of integers, find the length of longest increasing
subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.
Note that there may be more than one LIS combination, it is only necessary for
you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
 */

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;

    auto cur = nums.begin();
    for (int &num : nums) {
      auto insert = lower_bound(nums.begin(), cur, num);
      // 返回索引在[nums.begin(),cur)中大于等于num的第一个元素的迭代器
      *insert = num;
      if (insert == cur)
        cur++;
    }
    return cur - nums.begin();
  }
};
