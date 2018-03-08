/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
    void binaryTreePaths(vector <string> &res, TreeNode *root, string str) {
        if (!root->left && !root->right) { // 叶结点
            res.push_back(str);
            return;
        }
        if (root->left)
            binaryTreePaths(res, root->left, str + "->" + to_string(root->left->val));
        if (root->right)
            binaryTreePaths(res, root->right, str + "->" + to_string(root->right->val));
    }

    vector <string> binaryTreePaths(TreeNode *root) {
        vector <string> res;
        if (!root) return res;

        binaryTreePaths(res, root, to_string(root->val));
        return res;
    }
};