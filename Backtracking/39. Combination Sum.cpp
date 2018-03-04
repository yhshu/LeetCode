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
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector <vector<int>> res;
        combinationSum(candidates, candidates.begin(), cur, res, target);
        return res;
    }

    void
    combinationSum(vector<int> &candidates, vector<int>::iterator it, vector<int> &cur, vector <vector<int>> &res,
                   int target) {
        if (target == 0) {
            res.push_back(cur);
        }
        for (auto i = it; i != candidates.end() && target - *i >= 0; i++) {
            cur.push_back(*i);
            combinationSum(candidates, i, cur, res, target - *i);
            cur.pop_back();
        }
    }
};