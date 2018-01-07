/*
 Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
	\
	 2
	/
   3
return [1,3,2].
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
	vector<int> inorderTraversal(TreeNode* root) {
		// µÝ¹éÖÐÐò±éÀú
		InorderTraversal(root);
		return res;
	}

	void InorderTraversal(TreeNode *root)
	{
		if (!root)
			return;
		InorderTraversal(root->left);
		res.push_back(root->val);
		InorderTraversal(root->right);
	}

private:
	vector<int>res;
};