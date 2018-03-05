/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode *root) {
        // 层次遍历二叉树，记录每层最右
        vector<int> res;
        queue <TreeNode *> q;
        if (root == nullptr)return res;
        q.push(root);
        q.push(nullptr);
        int t;
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur == nullptr) // 层间分隔
            {
                res.push_back(t);
                if (!q.empty()) {
                    q.push(nullptr);
                }
            } else {
                t = cur->val;
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }
        return res;
    }
};