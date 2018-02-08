/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector <vector<int>> pathSum(TreeNode *root, int sum) {
        vector <vector<int>> res;
        vector<int> cur_path;
        findPath(root, sum, cur_path, res);
        return res;
    }

private:
    void findPath(TreeNode *root, int sum, vector<int> &cur_path, vector <vector<int>> &res) {
        if (!root) return;
        cur_path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && sum == root->val)
            res.push_back(cur_path); // 到达叶结点且符合条件
        else {
            findPath(root->left, sum - root->val, cur_path, res);
            findPath(root->right, sum - root->val, cur_path, res);
        }
        cur_path.pop_back(); // 回溯
    }
};