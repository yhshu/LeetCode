/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 */

class Solution {
public:
    vector <vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector <vector<int>> res;
        vector<int> sol;
        bool used[nums.size()] = {};
        permuteUnique(nums, used, sol, res);
        return res;
    }

    void permuteUnique(vector<int> &nums, bool used[], vector<int> &sol, vector <vector<int>> &res) {
        if (sol.size() == nums.size()) {
            res.push_back(sol);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i] && (i == 0 || nums[i - 1] != nums[i] || used[i - 1])) {
                // 如果要将nums[i]添加到sol，必须保证在nums[i]之前的与其值相同的数均已被添加，以避免res中重复
                used[i] = true;
                sol.push_back(nums[i]);
                permuteUnique(nums, used, sol, res);
                used[i] = false;
                sol.pop_back();
            }
        }
    }
};