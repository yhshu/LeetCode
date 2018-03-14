/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

 */

class Solution {
public:
    vector <vector<int>> permute(vector<int> &nums) {
        // 本题可直接调用next_permutation
        // 使用如下回溯法，顺序并不严格
        vector <vector<int>> res;
        permute(nums, 0, res);
        return res;
    }

    void permute(vector<int> &nums, int start, vector <vector<int>> &res) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            permute(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
};