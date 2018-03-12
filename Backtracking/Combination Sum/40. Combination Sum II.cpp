/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
 */

class Solution {
public:
    vector <vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // candidates中的每个元素只选一次或不选，加和为target
        sort(candidates.begin(), candidates.end());
        vector <vector<int>> res;
        vector<int> sol;
        combinationSum2(res, candidates, target, 0, sol);
        return res;
    }

    void combinationSum2(vector <vector<int>> &res, vector<int> &candidates, int remain, int start,
                         vector<int> &sol) {
        if (remain == 0) {
            res.push_back(sol);
            return;
        }
        for (int i = start; i < candidates.size() && remain - candidates[i] >= 0; i++) {
            if (i > start && candidates[i] == candidates[i - 1]) // 跳过重复元素
                continue;
            sol.push_back(candidates[i]);
            combinationSum2(res, candidates, remain - candidates[i], i + 1, sol);
            sol.pop_back();
        }
    }
};