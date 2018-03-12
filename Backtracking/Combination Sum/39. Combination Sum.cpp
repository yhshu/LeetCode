/*
Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
  [7],
  [2, 2, 3]
]
 */


class Solution {
public:
    vector <vector<int>> combinationSum(vector<int> &candidates, int target) {
        // candidates中的每个元素可选多次，加和为target
        sort(candidates.begin(), candidates.end());
        vector<int> sol;
        vector <vector<int>> res;
        combinationSum(candidates, 0, sol, res, target);
        return res;
    }

    void combinationSum(vector<int> &candidates, int start, vector<int> &sol, vector <vector<int>> &res,
                        int remain) {
        if (remain == 0) {
            res.push_back(sol);
            return;
        }
        for (int i = start; i < candidates.size() && remain - candidates[i] >= 0; i++) {
            sol.push_back(candidates[i]);
            combinationSum(candidates, i, sol, res, remain - candidates[i]);
            sol.pop_back();
        }
    }
};