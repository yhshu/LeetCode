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
		vector<int>res;
		stack<TreeNode *>stack;
		while (root != nullptr)
		{
			res.push_back(root->val);
			if (root->right != nullptr)
				stack.push(root->right);
			root = root->left;
			if (root == nullptr && !stack.empty())//rootÎª¿Õ£¬Õ»·Ç¿Õ
			{
				root = stack.top();
				stack.pop();
			}
		}
		return res;
	}
};