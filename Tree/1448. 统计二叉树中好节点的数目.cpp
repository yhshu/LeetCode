/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + help(root->left, root->val) + help(root->right, root->val);
    }

    int help(TreeNode* root, int maxVal) {
        if (root == nullptr) return 0;
        int t = 0;
        if (root->val < maxVal) t = 0;
        else t = 1;
        return t + help(root->left, max(maxVal, root->val)) + help(root->right, max(maxVal, root->val));
    }
};
