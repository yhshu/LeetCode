/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

	1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
	1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
    queue<TreeNode *> q1;
    queue<TreeNode *> q2;

    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        TreeNode *left, *right;

        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()) {
            TreeNode *left = q1.front();
            q1.pop();
            TreeNode *right = q2.front();
            q2.pop();
            if (left == nullptr && right == nullptr)
                continue;
            if (left == nullptr || right == nullptr)
                return false;
            if (left->val != right->val)
                return false;

            q1.push(left->left);
            q2.push(right->right);
            q1.push(left->right);
            q2.push(right->left);
        }
        return true; // 所有结点比对完成
    }
};