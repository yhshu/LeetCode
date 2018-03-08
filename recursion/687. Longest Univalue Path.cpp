/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

Note: The length of path between two nodes is represented by the number of edges between them.

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output:

2
Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output:

2
Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
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
    int longestUnivaluePath(TreeNode *root) {
        int lup = 0;
        if (root) dfs(root, lup);
        return lup;
    }

private:
    int dfs(TreeNode *node, int &lup) {
        int l = node->left ? dfs(node->left, lup) : 0; // 从左子结点开始
        int r = node->right ? dfs(node->right, lup) : 0; // 从右子结点开始
        int resl = node->left && node->left->val == node->val ? l + 1 : 0; // 由root向左
        int resr = node->right && node->right->val == node->val ? r + 1 : 0;  // 由root向右
        lup = max(lup, resl + resr);
        return max(resl, resr);
    }
};