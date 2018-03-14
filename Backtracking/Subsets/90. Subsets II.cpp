/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 */
class Solution {
public:
    void backtrack(vector<int> &nums, int start, vector<int> &sub, vector <vector<int>> &res) {
        res.push_back(sub);
        for (int i = start; i < nums.size(); i++) {
            if (i == start || nums[i] != nums[i - 1]) { // 该if语句是 78. Subsets 和本题 Subsets II 回溯解法的唯一差别
                sub.push_back(nums[i]);
                backtrack(nums, i + 1, sub, res);
                sub.pop_back();
            }
        }
    }

    vector <vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector <vector<int>> res;
        vector<int> sub;
        backtrack(nums, 0, sub, res);
        return res;
    }
};