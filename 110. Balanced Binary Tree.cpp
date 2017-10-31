/*
 * Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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

 // root平衡的条件是，root任意子树平衡且abs(h(root->left)-h(root->right))<=1
class Solution {
public:
	int dfsHeight(TreeNode *root)
	{
		if (!root)
			return 0;
		int leftHeight = dfsHeight(root->left);
		if (leftHeight == -1)
			return -1;
		int rightHeight = dfsHeight(root->right);
		if (rightHeight == -1)
			return -1;

		if (abs(leftHeight - rightHeight) > 1)
			return -1;
		return max(leftHeight, rightHeight) + 1;
	}
	bool isBalanced(TreeNode* root) {
		return dfsHeight(root) != -1;
	}
};