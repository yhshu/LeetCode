/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
\
2
/
3
return [1,2,3].
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
	vector<int> preorderTraversal(TreeNode* root) {
		PreorderTraversal(root);
		return res;
	}

	void PreorderTraversal(TreeNode* root)
	{
		if (!root)
			return;
		res.push_back(root->val);
		PreorderTraversal(root->left);
		PreorderTraversal(root->right);
	}
private:
	vector<int> res;
};