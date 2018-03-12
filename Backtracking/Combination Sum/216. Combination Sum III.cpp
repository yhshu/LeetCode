/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
 */

class Solution {
public:
    vector <vector<int>> combinationSum3(int k, int n) {
        // 1到9的九个数字，其中选k个，每个最多一次，加和为n
        vector <vector<int>> res;
        vector<int> sol;
        combinationSum3(res, sol, k, n);
        return res;
    }

    void combinationSum3(vector <vector<int>> &res, vector<int> &sol, int k, int remain) {
        if (sol.size() == k && remain == 0) { // 符合条件
            res.push_back(sol);
            return;
        }
        if (sol.size() < k) {
            for (int i = sol.empty() ? 1 : sol.back() + 1; i <= 9 && i <= remain; i++) {
                // 注意i的两个限定条件
                sol.push_back(i);
                combinationSum3(res, sol, k, remain - i);
                sol.pop_back();
            }
        }
    }
};