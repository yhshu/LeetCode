/*
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
 */

class Solution {
public:
    vector <vector<int>> findSubsequences(vector<int> &nums) {
        set <vector<int>> set;
        vector<int> sol;
        DFS(set, 0, nums, sol);
        vector <vector<int>> res(set.begin(), set.end());
        return res;
    }

    void DFS(set <vector<int>> &set, int start, const vector<int> &nums, vector<int> &sol) {
        if (sol.size() > 1)
            set.insert(sol);
        for (int i = start; i < nums.size(); i++) {
            if (sol.empty() || nums[i] >= sol.back()) {
                sol.push_back(nums[i]);
                DFS(set, i + 1, nums, sol);
                sol.pop_back();
            }
        }
    }
};