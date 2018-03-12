/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
 */

class Solution {
public:
    vector <vector<int>> combine(int n, int k) {
        // 从 1...n 取k个数的所有组合
        vector <vector<int>> res;
        if (k > n)
            return res;
        vector<int> comb;
        combine(res, comb, 0, 0, n, k);
        return res;
    }

    void combine(vector <vector<int>> &res, vector<int> &comb, int start, int step, int &n, int &k) {
        // 第step+1位要填的数的范围是[start+1, n]
        if (step == k) {
            res.push_back(comb);
            return;
        }
        for (int i = start; i < n; i++) {
            comb.push_back(i + 1);
            combine(res, comb, i + 1, step + 1, n, k);
            comb.pop_back();
        }
    }
};