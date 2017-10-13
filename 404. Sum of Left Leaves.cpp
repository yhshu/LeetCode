/*
 * Find the sum of all left leaves in a given binary tree.

Example:

	3
   / \
  9  20
	/  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == nullptr || (root->left == nullptr && root->right == nullptr))
			return 0;
		countLeftLeaves(root->left, root);
		countLeftLeaves(root->right, root);
		return res;
	}

	void countLeftLeaves(TreeNode* cur, TreeNode *par)
	{
		if (cur != nullptr)
		{
			countLeftLeaves(cur->left, cur);
			countLeftLeaves(cur->right, cur);
			if (par->left == cur && isLeaf(cur))
			{
				res += cur->val;
			}
		}
	}

	bool isLeaf(TreeNode *node)
	{
		if (node == nullptr)return false;
		return (node->left == nullptr && node->right == nullptr) ? true : false;
	}

private:
	int res = 0;
};