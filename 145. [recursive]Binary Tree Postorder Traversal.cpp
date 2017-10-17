/*
 * Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
	\
	 2
	/
   3
return [3,2,1].
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
	vector<int> postorderTraversal(TreeNode* root) {

		PostOrderTraversal(root);
		return res;
	}

	void PostOrderTraversal(TreeNode *root)
	{
		if (root != nullptr)
		{
			PostOrderTraversal(root->left);
			PostOrderTraversal(root->right);
			res.push_back(root->val);
		}
	}

private:
	vector<int>res;
};