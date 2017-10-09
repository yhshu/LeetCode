/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
2
/ \
1   3
Binary tree [2,1,3], return true.
Example 2:
1
/ \
2   3
Binary tree [1,2,3], return false.
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
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, NULL, NULL);//重载，不是递归
	}

	bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) //子树中所有结点的值在 minNode 和 maxNode 的值之间
	{
		if (!root) return true;
		if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val) //首先判断本次调用是否存在最大值结点和最小值结点，如果存在判断root是否满足要求
			return false;
		return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
	}
};