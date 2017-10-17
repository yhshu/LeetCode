/*
 *Invert a binary tree.

	 4
   /   \
  2     7
 / \   / \
1   3 6   9
to
	 4
   /   \
  7     2
 / \   / \
9   6 3   1
 */
 /**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root != nullptr)
		{
			if (root->left != nullptr)//有左子结点 
			{
				TreeNode *right = root->right;
				root->right = root->left;
				root->left = right;
			}
			else if (root->right != nullptr)//没有左子结点，有右子结点
			{
				root->left = root->right;
				root->right = nullptr;
			}
			invertTree(root->left);
			invertTree(root->right);
		}
		return root;
	}
};