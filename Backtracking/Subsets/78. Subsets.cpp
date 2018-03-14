/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
 */

class Solution {
public:
    void backtrack(vector<int> &nums, int start, vector<int> &sub, vector <vector<int>> &res) {
        res.push_back(sub);
        for (int i = start; i < nums.size(); i++) {
            sub.push_back(nums[i]);
            backtrack(nums, i + 1, sub, res);
            sub.pop_back();
        }
    }

    vector <vector<int>> subsets(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector <vector<int>> res;
        vector<int> sub;
        backtrack(nums, 0, sub, res);
        return res;
    }
};